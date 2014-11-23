clear all
close all
clc


% we have to specify every value of the cell vector for consistency with
% the cycle inside the function 
subchain1 = [6 3];
target_link{1} = subchain1;
% reference parameters
type = {'cartesian_x','cartesian_rpy'};
control_type = {'tracking','regulation'};
type_of_traj = {'func','func'};
traj = {'circular','none'};
time_law = {'linear','none'};

% type = {'cartesian_rpy'};
% control_type = {'regulation'};
% type_of_traj = {'func'};
% traj = {'none'};
% time_law = {'none'};

%parameters first chains
geom_parameters{1,1} = [0.2 0 -pi/2 -pi/4 0 -0.5 0.3]; % Circular trajectory 
geom_parameters{1,2} = [0 0 -pi/2]; % orientation regulation

%geom_parameters = [-0.2 0.3 0.2 0.2 0.3 0.2];% Rectilinear trajectory
%geom_parameters =  [-0.2 0.3 0.2]; % position regulation

time_struct.ti = 0;
time_struct.tf = 10;
time_struct.step = 0.1;

dim_of_task{1,1}={[1;1;1]}; dim_of_task{1,2}={[1;1;1]};

%% test substructure
[p560] = MdlPuma560();
robots{1} = p560;

chains = SubChains(target_link,robots);

%% test  func references
% if type_of_task = sampled i have to specify the Time to reach the
% end of the trajectories that is equal to the simulation time
reference = References(target_link,type,control_type,traj,geom_parameters,time_law,time_struct,dim_of_task,type_of_traj);
reference.BuildTrajs();


% perfomance measure 
tic
for i = 1:chains.GetNumChains()
   for j = 1:chains.GetNumTasks(i)

       for t=time_struct.ti:time_struct.step:time_struct.tf

         [p_cur,pd_cur,pdd_cur]=reference.GetTraj(i,j,t);

       end 

   end
end
toc


%% test sampled reference 

s = Linear(time_struct.tf);
test_parameters = [0.2 0 -pi/2 2*pi -pi/4 0 -0.5 0.3]; 
if(strcmp(traj,'circular')) 
    [p,pd,pdd,time] = Circular(s,time_struct,geom_parameters,type_of_traj);
    [p_test,pd_test,pdd_test] = CircularTest(time_struct,'sampled',test_parameters);
end

%% plot trajectories (only the first one of the first chain)

if(strcmp(type_of_traj{1,1},'func')) 
  
    p_tot=[];
    pd_tot=[];
    pdd_tot=[];
    for t=time_struct.ti:time_struct.step:time_struct.tf
        
        
        p_cur=feval(reference.trajectories{1,1}.p,t);
        pd_cur=feval(reference.trajectories{1,1}.pd,t);
        pdd_cur=feval(reference.trajectories{1,1}.pdd,t);

        p_tot = [p_tot,p_cur];
        pd_tot = [pd_tot,pd_cur];
        pdd_tot = [pdd_tot,pdd_cur];
        
    end
    
elseif(strcmp(type_of_traj{1,1},'sampled'))
    p_tot = reference.trajectories{1,1}.p;
    pd_tot = reference.trajectories{1,1}.pd;
    pdd_tot = reference.trajectories{1,1}.pdd;
end


hold on;axis equal;
p560.plot(qz);
plot3(p_tot(1,1:end),p_tot(2,1:end),p_tot(3,1:end));
%% alpha function

number_of_basis = 10;
redundancy = 3;
kp = 10;
kd = 2*sqrt(kp);
Po = 0;
Vo = 0;
Pd = 0; 
Vd = 0;
alpha_z = 0.1;
train = true;
number_of_pivot = 5;
step = 0.01;
theta = 1*ones(number_of_basis,reference.GetNumTasks());
values = 1*ones(reference.GetNumTasks());
%alphas = DMP.BuildCellArray(reference.GetNumTasks(),time_struct,number_of_basis,redundancy,kp,kd,Po,Vo,Pd,Vd,alpha_z,train,number_of_pivot,step);
alphas = ConstantAlpha.BuildCellArray(values,time_struct);

% %% test controller 
% 
% % test on J J_dot and fkine
% p560.GetNumSubLinks(1)
% qz(1:p560.GetNumSubLinks(1))
% %structure of jacobian
% fkin = p560.sub_chains(1).fkine(qr(1:p560.GetNumSubLinks(1)));
% J = p560.sub_chains(1).jacob0(qr(1:p560.GetNumSubLinks(1))','trans');
% % J_dot is multiplied by qd inside the function so i have only to get the
% % right portion
% J_dot = p560.sub_chains(1).jacob_dot(qz(1:p560.GetNumSubLinks(1)),0.5*ones(p560.GetNumSubLinks(1),1));
% 
% 
% 
% metric = {'M^(1/2)';'M^(1/2)'};  % N^(1/2) = (M^(-1))^(1/2) = M^(1/2);        
% ground_truth = false; 
% %kp = 1500; %linear and exponential tracking
% %kp = 1497  % regulation 
% kp = [1497, 1500]; % row vector
% K_p = zeros(3,3,size(kp,2));
% K_d = zeros(3,3,size(kp,2));
% for par = 1:size(kp,2)
%     K_p(:,:,par) = kp(par)*eye(3);  
%     kd = 2*sqrt(kp(par));
%     K_d(:,:,par) = kd*eye(3); 
% end
% combine_rule = {'sum'}; 
% display_opt.step = 0.01;
% display_opt.trajtrack = true;
% 
% % for using package functions we have to call the name of the package before
% % the constructor
% controller = Controllers.UF(p560,reference,alphas,metric,ground_truth,K_p,K_d,combine_rule,display_opt);
% 
% value =1;
% try
% tic
% options= odeset('MaxStep',0.001);
% fixed_step = false;
% time_sym_struct = time_struct;
% time_sym_struct.step = 0.001;
% [t, q, qd] = controller.subchains.nofriction().fdyn(time_sym_struct,controller,qz,zeros(1,controller.subchains.n),fixed_step,options);
% toc
% catch error
%     
%     disp(error);
%     value = 0;
%     
% end
% 
% 
% controller.plot3d(q,t);
% %controller.plot(q,t);
% 
% 
% %% test instance
% 
% % test alpha function
% % number_of_basis = 4;
% % redundancy = 3;
% % alpha = RBF(time_struct,number_of_basis,redundancy);
% % % the parameters have to be a column vector !!!!
% % alpha.ComputeNumValue(ones(number_of_basis,1));
% % %plot(alpha.sample.time,alpha.sample.normvalues);
% % %alpha.PlotBasisFunction();
% % 
% % 
% % %[zp ,zpd ,zpdd , scaled_time] = RecordTrajectory(5,0.01);
% % 
% % number_of_basis = 10;
% % redundancy = 3;
% % kp = 10;
% % kd = 2*sqrt(kp);
% % alpha_z = 0.1;
% % number_of_pivot = 5;
% % step = 0.01;
% % alpha1 = DMP(time_struct,number_of_basis,redundancy,kp,kd,alpha_z);
% % [p_init,v_init,p_end,v_end,theta] = alpha1.TrainByDraw(number_of_pivot,step);
% % alpha1.ComputeNumValue(p_init,v_init,p_end,v_end,theta);
% % % plot results
% % figure
% % plot(alpha1.sample.time,alpha1.sample.normvalues);
% % figure
% % alpha1.PlotBasisFunction();








