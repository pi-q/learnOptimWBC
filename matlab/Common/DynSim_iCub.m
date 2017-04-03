%%
%  This is the main program for integrating the forward dynamics of the robot iCub in matlab.
%  It integrates the robot state defined in forwardDynamics_SoT.m and the user can set
%  how many feet are on the ground, decide if activate floating base or not

% #TODO substitute icub with controller.subchains
function [t, q, qd] = DynSim_iCub(controller,params)
    WS = controller.GetWholeSystem();
    %% Updating the robot position and define the world link
    WS.SetWorldFrameiCub(params.qjInit,params.dqjInit,params.dx_bInit,params.omega_bInit,params.root_reference_link);
    WS.ComputeSupportPoly(params);
    [~,T_b,~,~] = WS.GetState();

    params.chiInit = [T_b; params.qjInit; WS.state.dx_b; WS.state.w_omega_b; params.dqjInit];
    %% Integrate forward dynamics
    if params.demo_movements == 0
        options = odeset('RelTol',1e-3,'AbsTol', 1e-4);
    else
        options = odeset('RelTol',1e-6,'AbsTol',1e-6);
    end

    params.lfoot_ini = wbm_forwardKinematics('l_sole');
    params.rfoot_ini = wbm_forwardKinematics('r_sole');
    params.lu_leg_ini = wbm_forwardKinematics('l_upper_leg');
    params.ru_leg_ini = wbm_forwardKinematics('r_upper_leg');
    
    
    %% initilization for controller visual
     controller.visual_param.t    =  [];
     %controller.visual_param.fc   =  [];
     controller.visual_param.tau  =  [];
     controller.visual_param.qj   =  [];
     controller.visual_param.zmp  =  [];
     controller.visual_param.xCoM =  [];

    forwardDynFunc  = @(t,chi)forwardDynamics(t,chi,controller,params);

    try                        
        [t,chi,visual_param] = ode15s(forwardDynFunc,params.tStart:params.sim_step:params.tEnd,params.chiInit,options);
        q = chi(:,1:7+WS.ndof);
        qd = chi(:,8+WS.ndof:end);
        %delete(params.wait)
    catch err
        disp('integration error');
        rethrow(err);
    end
end

function [dchi,visual_param]=forwardDynamics(t,chi,controller,param)
    t
    %% Config parameters
    import WBM.utilities.dquat;
    % i get the pointer to the whole system
    if isempty(controller.current_time)
        controller.current_time = tic;
    end

    icub = controller.GetWholeSystem();
    % waitbar(t/param.tEnd,param.wait)
    ndof = icub.ndof;
    % disp(t)

    %% Extraction of state
    [state,x_b,qt_b,w_R_b,base_pose,q,dx_b,w_omega_b,qd,Nu]=icub.State(chi);

    %% Update state (in the robot model)
    wbm_setWorldFrame(w_R_b,x_b,[0 0 -9.81]');
    wbm_updateState(q,qd,[dx_b;w_omega_b]);

    %% dynamics
    [dynamic,M,h,g,H,C_nu,JCoM,dJCoM_nu,JH,dJH_nu] = icub.Dynamics();
    
    %% compute com position (TODO (provisory) i need to reorder how the kinematics is computed)
    poseCoM  = wbm_forwardKinematics(icub.state.w_R_b,icub.state.x_b,q,'com');
    xCoM     = poseCoM(1:3);
    %% update contact state (i  suppose that i start to move after 0.1 seconds)
    if(t>0.1)
       param.feet_on_ground(3) = 0;
       param.feet_on_ground(4) = 0; 
       param.numContacts = sum(param.feet_on_ground);
       param.contact_sym.state(3) = 0;
       param.contact_sym.state(4) = 0;
       param.contact_sym.UpdateContact();
    end
  
    %% TODO
    %% contact jacobian
    [jacobian_contact,Jc_sym,dJcNu_sym] = icub.ContactJacobians(param,param.contact_sym);
    %% Control torques calculation
    tau = controller.Policy(t,q,qd,[],jacobian_contact,param); 
    %% torque saturation
    tau(tau>param.torque_saturation)  = param.torque_saturation;
    tau(tau<-param.torque_saturation) = -param.torque_saturation;

    %% contact dynamic simulation    
    [tauContact,fc]=DynSim_iCubContacts(ndof,state,dynamic,Jc_sym,dJcNu_sym,param,tau);
    %% compute zmp
    [zmp]=DynSim_iCubZmp(fc,param); 
    %% State derivative computation
    % Need to calculate the quaternions derivative
    b_omega_w = transpose(w_R_b)*w_omega_b; %% TODO floating base flag required (parameter of the simulator)
    dqt_b   = dquat(qt_b,b_omega_w);   %% TODO floating base flag required (parameter of the simulator)
    Nu      = [dx_b;dqt_b;qd];
    dNu     = M\(tauContact + [zeros(6,1); tau]-h);
    dchi    = [Nu;dNu];

    %% for debug
    %if toc(controller.current_time) > param.maxtime;
    %    controller.current_time = [];
    %    error('Stopped. Taking too long.')
    %end
    %% Visualization
    % These are the variables that can be plotted by the visualizer.m
    % function
     %controller.visual_param.Href      =  [M(1,1)*desired_x_dx_ddx_CoM(:,2);zeros(3,1)];
     %controller.visual_param.H         =  H;
     %controller.visual_param.pos_feet  =  [l_sole;r_sole];
     controller.visual_param.t(end + 1)      =  t;
     %controller.visual_param.fc(end + 1,:)   =  fc';
     controller.visual_param.tau(end +1 ,:)  =  tau';
     controller.visual_param.qj(end + 1,:)   =  q';
     controller.visual_param.zmp(end + 1,:)  =  zmp;
     controller.visual_param.xCoM(end + 1,:) =  xCoM';
     %controller.visual_param.error_com =  errorCoM;
     %controller.visual_param.f0        =  f0;

end








