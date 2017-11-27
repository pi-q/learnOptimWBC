
%%%;;

% This configuration is the same as configuration #4, but uses the WBM-Toolbox instead.
% Note: This configuration file works only if the WBM-Toolbox is installed on the system.
import WBM.*
import WBM.RobotModel.iCub_arms_torso_free.*

%% GENERAL PARAMETERS
% for other strucutures
time_struct.ti = 0;
time_struct.tf = 20;
time_struct.step = 0.001;

%% TASK PARAMETERS
%name_dat = 'iCub_1.0';
%path=LoadParameters(name_dat);
%load(path);
%% TYPE OF CONTROLLER
CONTROLLERTYPE ='UF';   % GHC or UF
%%

%SUBCHAIN PARAMETERS
subchain1 =  {'r_hand','r_elbow_1','l_hand','l_elbow_1','none','r_hand','l_hand'}; % space (cartesian or joint space)
target_link{1} = subchain1;

%% Robot
wf2fixLnk   = true; % set the world frame to a fixed link
wbm_icub    = initRobotICub_atf(wf2fixLnk);
icub_model  = wbm_icub.robot_model;
icub_config = wbm_icub.robot_config;

icub_config.nCstrs = 4;
icub_config.ccstr_link_names = horzcat(icub_config.ccstr_link_names, {'l_hand', 'r_hand'});

strCmt = 'iCub model using the WBM-Library.';
opt    = struct('name', '', 'manufacturer', '', 'comment', strCmt, ...
                'ee_links', [], 'plotopt3d', []);

bot1    = iCubWBC(icub_model, icub_config, wf2fixLnk);
chain_1 = MultChainTreeICub(bot1, 'l_sole', opt);

robots{1} = chain_1;
chains = SubChains(target_link,robots,bot1);
%%  REFERENCE PARAMETERS
deg = pi/180;
% primary trajectory
traj_type = {'cartesian','cartesian','cartesian','cartesian','joint','cartesian','cartesian'};
control_type = {'x','x','x','x','none','x','x'}; % rpy is also possible instead of x ... (none = control type has no parameters, x ... cartesian)
type_of_traj = {'sampled','sampled','sampled','sampled','sampled','sampled','sampled'}; % computing fixed time steps (func)
geometric_path = {'fixed','fixed','fixed','fixed','fixed','fixed','fixed'}; % like the previous but for geometric
time_law = {'none','none','none','none','none','none','none'}; % time restriction on every sub-chain (tstart, tfinish)
%parameters first chains
% cartesian coordinates for the trajectory (goal-points of each joint) - elementary tasks
geom_parameters{1,1} = [0.3,-0.17,0.68];    %r_e_e_point (goal-point)
geom_parameters{1,2} = [0.18,-0.23,0.68];   %[0.21,-0.25,0.68];	%r_elbow_point
geom_parameters{1,3} = [0.3,0.0248,0.68];   %l_e_e_point
geom_parameters{1,4} = [0.18,0.1038,0.68];  %[0.21,0.1138,0.68];   %l_elbow_point
geom_parameters{1,5} = [0 0.785398163397448 0 0 0 0.523598775598299 0 0 0.785398163397448 0 0 0 0.523598775598299 0 0 0 0]; % 17 dof (joint-type), to minimize the torques in the fitness function
geom_parameters{1,6} = [0.28,-0.16,0.7463];   %r_end_pt  [0.2512,-0.16,0.76] [0.28,0.0148,0.7463];
geom_parameters{1,7} = [0.28,0.0148,0.7463];	%l_end_pt [0.21,0.0148,0.77]
% dimension of every task (cartesian) ... activate or deactivate the dimensons (1,0,1)
dim_of_task{1,1}=[1;1;1]; dim_of_task{1,2}= [1;1;1];
dim_of_task{1,3}= [1;1;1]; dim_of_task{1,4}= [1;1;1];
dim_of_task{1,5}= ones(bot1.ndof,1); % joint-type (maybe not working in the code)
dim_of_task{1,6}= [1;1;1]; dim_of_task{1,7}= [1;1;1];

% secondary trajectory
% (there is no need there for the second trajectory, maybe it doesn't need the same length as above - just copy paste)
traj_type_sec = {'none','none','none','none','none','none','none'};
control_type_sec = {'rpy','rpy','rpy','rpy','rpy','rpy','rpy'};
type_of_traj_sec = {'func','func','func','func','func','func','func'};
geometric_path_sec = {'fixed','fixed','fixed','fixed','fixed','fixed','fixed'};
time_law_sec = {'linear','linear','linear','linear','linear','linear','linear'};
%parameters first chains
% parameters for the secondary trajectory (will be not used)
geom_parameters_sec{1,1} = [pi/2 0 -pi/2]; % regulation
geom_parameters_sec{1,2} = [-0.309 -0.469 0.581];
geom_parameters_sec{1,3} = [-0.309 -0.469 0.581];
geom_parameters_sec{1,4} = [-0.309 -0.469 0.581];
geom_parameters_sec{1,5} = [-0.309 -0.469 0.581];
geom_parameters_sec{1,6} = [-0.309 -0.469 0.581];
geom_parameters_sec{1,7} = [120 116 90 0 0 0 0]* deg;
dim_of_task_sec{1,1}=[1;1;1];
dim_of_task_sec{1,2}=[1;1;1];
dim_of_task_sec{1,3}=[1;1;1];
dim_of_task_sec{1,4}=[1;1;1];
dim_of_task_sec{1,5}=[1;1;1];
dim_of_task_sec{1,6}=[1;1;1];
dim_of_task_sec{1,7}= ones(bot1.ndof,1);

switch CONTROLLERTYPE
    case 'UF'
        % REPELLER PARAMETERS
        % scenario dependant
        rep_subchain = [7];
        rep_target_link{1} = rep_subchain;
        rep_type = {'cartesian_x'};
        rep_mask {1,1}=[1,1,1];
        rep_type_of_J_rep = {'DirectionCartesian'};
        for ii=1:chains.GetNumChains()
            chain_dof(ii) = chains.GetNumLinks(ii);
        end
        UF_StaticParameters
    case 'GHC'
        GHC_StaticParameters
    otherwise
        warning('Unexpected control method')
end

%% SCENARIO
name_scenario = 'iCub_4';

%% RBT SIMULATOR PARAMETERS
time_sym_struct = time_struct;
time_sym_struct.step = 0.001;
% TODO generalize for multichain

simulator_type = {'icub_matlab'};
if strcmp(simulator_type{1},'rbt')
    % rbt sim
    qi{1} = qz;
    %qi{1} = zeros(1,chains.GetNumLinks(1)); %stretched arm
    qdi{1} = zeros(1,chains.GetNumLinks(1));
    options= [];
    % define the type of integration of the sytem of differential equation
    fixed_step = false; %true;
    torque_saturation =100000; % high value == no saturation
    maxtime = 100; % maximum time before a simulation is stopped for being too long
elseif strcmp(simulator_type{1},'icub_matlab')
    % iCub sim
    %% building initial configuration
    qi{1} = [];
    qdi{1} = [];
    list_of_kin_chain = {'trunk','left_arm','right_arm'}; % trunk = torso, set not listed but set into default position
    joints_initial_values{1,1} = [0.0  0.0  0.0];
    joints_initial_values{1,2} = [0.0  30.0  0.0  45.0  0.0 0.0 0.0];
    joints_initial_values{1,3} = [0.0  30.0  0.0  45.0  0.0 0.0 0.0];

    params.feet_on_ground =  [1,1];
    params.numContacts = sum(params.feet_on_ground,2);
    if       params.feet_on_ground(1) == 1 && params.feet_on_ground(2) == 1
        % contact constraints for 2 feet on ground
        params.contactLinkNames      = {'l_sole','r_sole'};
    elseif   params.feet_on_ground(1) == 1 && params.feet_on_ground(2) == 0
        % contact constraints for left foot on ground
        params.contactLinkNames      = {'l_sole'};
    elseif   params.feet_on_ground(1) == 0 && params.feet_on_ground(2) == 1
        % contact constraints for right foot on ground
        params.contactLinkNames      = {'r_sole'};
    end
    params.active_floating_base = false; % put it to false, since it is not working - robot will stay straight, if true robot fall to the ground ...
    params.qjInit      = bot1.InitializeState(list_of_kin_chain, params.feet_on_ground, joints_initial_values);
    % for special initializaton (direct coordinantes in joint-space)
    %params.qjInit      = [0.0606953245641302 1.41994832618389 -6.74178292930099e-08 -1.14179614686264e-07 -0.984861184692183 0.761783299026996 0.849107718577681 1.82446511832070e-07 1.23867031369701 -3.00036385696852e-08 6.49994328883225e-08 -1.14151145574591 0.575459848754039 0.945960370485754 -6.03357679751874e-08 0.324676495831434 -0.0358523080153591]';

    params.dqjInit     = zeros(bot1.ndof,1); % initial angular speed for the joints
    % icub starting velocity floating base
    params.dx_bInit    = zeros(3,1); % initial base velocity (cartesian)
    params.omega_bInit = zeros(3,1); % initial angular speed of the base
    % root reference link;
    if params.feet_on_ground(1) == 1
        params.root_reference_link ='l_sole';
    else
        params.root_reference_link ='r_sole';
    end
    params.tStart   = time_sym_struct.ti;
    params.tEnd     = time_sym_struct.tf;
    params.sim_step =  0.01;%time_struct.step;
    params.demo_movements = 0;
    params.maxtime = 100;
    params.torque_saturation = 100000;

end
%% Parameters Dependant on the type of controller

%%%EOF

switch CONTROLLERTYPE
    case 'UF'
        disp('UF_RUNTIMEPARAM')

        %%%;;

        %% PRIMARY REFERENCE PARAMETERS (this parameter only works if one of the specific trajectory has runtime parameters)
        numeric_reference_parameter{1,1} = [0.047180 0.359539 1.045565 0.374223 -0.069047 0.013630 -0.495463 -0.131683 0.668327 -0.184017 1.115775 0.884010 0.120701 0.837400 1.189048]';
        %% SECONDARY REFERENCE PARAMETERS
        secondary_numeric_reference_parameter{1,1} = [];
        %% REPELLERS PARAMETERS
        % GENERALIZE TO MULTICHAIN !!!
        rep_obstacle_ref = [1 2]; % if i change the order of ref obstacle i change the order of repellor in the stacked case
        J_damp = 0.01;
        % with this part i choose if for each repellers i want to use 3 or one
        % activation policy if 1 only one if 0 we have three activation policy
        single_alpha_chain1 = [1 1];
        single_alpha_chain2 = [1];
        single_alpha{1} = single_alpha_chain1;
        single_alpha{2} = single_alpha_chain2;
        type_of_rep_strct={'extended_decoupled','extended_combine','stacked' };

        %% ALPHA PARAMETERS
        choose_alpha = 'RBF';  % RBF , constant, handTuned

        %RBF
        number_of_basis = 5; %5; %10; %basis functions for the RBF
        redundancy = 2; %3; %overlap of the RBF
        value_range = [0 , 12];
        precomp_sample = false;
        % value of theta that we have to change when we want to execute the result
        % from the optimization step
        %numeric_theta = [0.068017 9.937933 10.629743 8.625690 4.620175 10.724682 6.943026 1.836172 6.005996 6.404127 1.499565 5.320011 5.059803 8.438304 2.319497 8.590403 9.120348 2.400932 9.071976 6.264097 ];
        %numeric_theta =[0.068017 9.937933 10.629743 8.625690 4.620175 10.724682 6.943026 1.836172 6.005996 6.404127 1.499565 5.320011 5.059803 8.438304 2.319497 8.590403 9.120348 2.400932 9.071976 6.264097 ];
        %numeric_theta =[2.3218    2.5695    6.8006    4.6558    5.7475    8.7383    3.5058    5.2817    6.9910    6.7590    4.5235    6.3875    7.3247    6.7258 8.5637];
        a = 14; b = 5; c = 14; d = 5; e = 1; f=0; g=0;
        numeric_theta = [a a a a a b b b b b c c c c c d d d d d e e e e e f f f f f g g g g g];
        % values of the optimized solutions reused for initialization (testing)
        %numeric_theta = [1.11087134108495 12.5305550089167 5.08866531318563 11.3506839783115 7.04742423600904 -8.78460218382942 12.4265180024550 -0.580054564040172 10.0938379456489 7.78471864294504 1.03847938458557 7.90094326509892 14 12.9866271074009 14 -1.59448676869201 4.91875693109553 1.16310380170680 13.1120720350808 5.32930377216845 -0.238565482650715 8.67768415160355 3.71249236039120 3.37630888571424 3.01213978936084];

        %8 of 2
        %[1.11087134108495 12.5305550089167 5.08866531318563 11.3506839783115 7.04742423600904 -8.78460218382942 12.4265180024550 -0.580054564040172 10.0938379456489 7.78471864294504 1.03847938458557 7.90094326509892 14 12.9866271074009 14 -1.59448676869201 4.91875693109553 1.16310380170680 13.1120720350808 5.32930377216845 -0.238565482650715 8.67768415160355 3.71249236039120 3.37630888571424 3.01213978936084];
        %6 of 2
        %[2.82386809016486 10.9157439707135 4.21941898170313 5.54633581174154 4.29176884783552 2.66470988741195 2.26509703062656 0.898475739722363 -4.36959112663677 1.84307995004280 1.67900016759073 7.63305865792555 5.29791043503921 5.86793260072585 11.0291811421804 -3.42443975092811 -11.5699037983794 6.06375247371970 -5.37201482801143 -0.702411094138079 -2.24991280354053 12.5818040065126 0.413555586912378 3.90689832275126 -0.202624809487876];

        %constant alpha
        value1 = 0*ones(chains.GetNumTasks(1));
        values{1} = value1;
        value_range_for_optimization_routine = [-0.5 , 1.5]; % this is a trick that im using to provide bound to the optimization procedure for parametric reference


        % HandTunedAlpha
        starting_value = [0 1 0] ;
        % inf means no transition but i have to add them because im using matrix
        % so i have to keep the number of element even between each row and between each col
        t1 = [13 inf;15 inf;0.5 3];
        ti(:,:,1) = t1;
        transition_interval1 = [0.5 0.5;1 0.5;0.5 1];
        transition_interval(:,:,1) = transition_interval1;
        %% CONTROLLER PARAMETERS
        combine_rule = {'sum'}; % sum or projector (with sum reppelers are removed)

        % the metric change between regularized and not regularized because in the
        % regularized case i have to do N^(-1)
        % not regularized case i have N^(-1/2)
        metric = {'M^(1)','M^(1)','M^(1)','M^(1)','M^(1)','M^(1)','M^(1)'};  % ex: if N = M^(-1) so N^(-1/2) = (M^(-1))^(-1/2) = M^(1/2);
        kd = [80,80,80,80,80,80,80];
        kp = [30,30,30,30,30,30,30]; % row vector one for each chain
        for i= 1:chains.GetNumChains()
            for par = 1:chains.GetNumTasks(i)
                if(strcmp(traj_type{i},'impedance'))
                    M = diag([1 1 1]);
                    D = diag([110 110 110]);
                    P =  kp(i,par)*eye(size(dim_of_task{i,par},1));
                    obj.M = M;
                    obj.D = D;
                    obj.P = P;
                    Param{i,par} = obj;
                else
                    K_p = kp(i,par)*eye(size(dim_of_task{i,par},1));
                    K_d = kd(i,par)*eye(size(dim_of_task{i,par},1));
                    obj.Kp = K_p;
                    obj.Kd = K_d;
                    Param{i,par} = obj;
                end
            end
        end
        % secondary task gains
        % will be not used ...
        kd = [90,90,90,110,110,110,110];
        kp = [40,40,40,70,70,70,70]; % row vector one for each chain
        for i= 1:chains.GetNumChains()
            for par = 1:chains.GetNumTasks(i)
                if(strcmp(traj_type_sec{i},'impedance'))
                    M = diag([1 1 1]);
                    D = diag([110 10 110]);
                    P =  kp(i,par)*eye(size(dim_of_task{i,par},1));
                    obj.M = M;
                    obj.D = D;
                    obj.P = P;
                    Param_secondary{i,par} = obj;
                else
                    K_p = kp(i,par)*eye(size(dim_of_task{i,par},1));
                    K_d = kd(i,par)*eye(size(dim_of_task{i,par},1));
                    obj.Kp = K_p;
                    obj.Kd = K_d;
                    Param_secondary{i,par} = obj;
                end
            end
        end
        % with this term i introduce a damped least square structure inside my
        % controller if regularizer is 0 i remove the regularizer action
        % ONE FOR EACH TASK
        regularizer_chain_1 = [0 0 0 0 0 0 0 0.001];
        regularized_chain_2 = [1];
        regularizer{1} = regularizer_chain_1;
        regularizer{2} = regularized_chain_2;

        %% CONSTRAINTS PARAMETERS
        constraints_values = bot1.createConstraintsVector;
        for k = 1:2:length(constraints_values)
            % for the fitness function ... compute also the constraint violations ...
            constraints_functions{k} = 'LinInequality'; % superior (compute the violation, angular position constraints) - important - Rule 1: Common
            constraints_functions{k+1} = 'LinInequality2'; % inferior () - important
        end
        distConstraints_values = [0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03]; % distances for the collissions constraints
        for k = 1:length(distConstraints_values)
            constraints_functions{end+1} = 'DistanceObs'; % constraint for collision detection - important
        end
        distConstraints_values = [0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03, 0.03]; % distances for the collissions constraints
        constraints_functions{end+1} = 'FixedDistanceEquality'; % penalties to to a fixed distance with a tolerance of epsilon (not needed for this experiment)
        fixDistance = 0.1748; %%%TO CHECK
        constraints_values = [constraints_values, distConstraints_values, fixDistance];   % vector that contains some constant that are used by the function in constraints_functions to compute the constraints_violation
        constraints_type = ones(1,length(constraints_values)); % vector that specifies if the constraints is a equality or an inequality. 1 disequality 0 equality
        constraints_type(end) = 0; %beacause the last constraint is an equality

        activate_constraints_handling = true;
        %% INSTANCE PARAMETER
        run_function = @RobotExperiment;
        fitness = @fitnessHumanoidsICub5; % fitness function ...
        % fitness = @fitnessHumanoidsIcub4; % fitness function ...
        clean_function = @RobotExperimentCleanData;

        if strcmp(simulator_type{1},'rbt')
            % TODO generalize for multichain
            input{1} = simulator_type{1};  % rbt / v-rep
            input{2} = qi;                 % initial position
            input{3} = qdi;                % initial velocity
            %------
            input{4} = time_sym_struct;    %time struct for simulation with fixed step
            input{5} = [];                 % here i have to insert the controller i will do that in init()
            input{6} = fixed_step;         % if is true i use ode4 (runge-kutta)
            input{7} = torque_saturation;  % i define the torque saturation that i want to apply
            input{8} = maxtime;            % maxtime before the simulation is stopped because is too long
        elseif strcmp(simulator_type{1},'icub_matlab')
            input{1} = simulator_type{1};  % rbt / v-rep
            input{2} = params;
            input{3} = time_sym_struct;
            input{4} = [];                 % here i have to insert the controller i will do that in init()
            input{5} = fixDistance;
        end
        %% CMAES PARAMETER
        %--- Starting value of parameters
        generation_of_starting_point = 'test'; % 'test', 'given', 'random'
        % user defined starting point = test
        %init_parameters = 6;
        a = 5; b = 5; c = 5; d = 5; e = 6; % numeric theta starting points (not working need to be in this case 7 (number of tasks))
        user_defined_start_action = [a a a a a b b b b b c c c c c d d d d d e e e e e];
        explorationRate = 0.1; %0.1; %0.5; %0.1;%[0, 1]
        niter = 100;  %number of generations
        cmaes_value_range = [-14 , 14];  % boudn that define the search space
        % will be used if you use an random starting point

        %cmaes_value_range{1} = [-14,-14,-14,-14,-14,-14,-14,-14,-14,-14,-14,-14,-14,-14,-14,-0.15,-0.15,-0.15 ];  % lower bound that define the search space
        %cmaes_value_range{2} = [14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0.15,0.15,0.15];  % upper bound that define the search space
        learn_approach = '(1+1)CMAES'; %CMAES (1+1)CMAES
        %--- Parameter for constraints method
        method_to_use = 'vanilla';  % adaptive , vanilla , empty
        epsilon = 0.001*ones(1,length(constraints_functions)); %vector with a number of value related to the number of constraints (used only with Aaptive constraints)
        %% FITNESS PARAMETERS

        %%%EOF
    case 'GHC'
        disp('GHC_RUNTIMEPARAM')

        %%%;;

        %% Constraints
        constraints_list={'vellimit','vellimit','torquelimit','torquelimit','obsavoid'}; %'obsavoid'
        cdata1 = [1;1000];
        cdata2 = [0;1000];
        cdata3 = [1;2000];
        cdata4 = [0;2000];
        cdata5 = [1;7];
        constraints_data = [cdata1, cdata2, cdata3, cdata4, cdata5];

        %% flag to choose type of alpha
        % RBF or chained
        choose_alpha = 'chained';

        %% ChainedAlpha
        transition_interval = 1.5;

        %% Alpha RBF
        %ALPHA PARAMETERS
        %rbf
        number_of_basis = 5;
        redundancy = 2;
        value_range = [0 , 12];
        precomp_sample = false;
        % value of theta that we have to change when we want to execute the result
        % from the optimization step in MainExec
        numeric_theta =[12 12 12 12 12 12 12 12 12 12 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0];

        %% Controller Parameters
        %UF and GHC
        % GHC
        epsilon = 0.002;
        regularization = 0.01;

        %% CMAES PARAMETER
        % starting value of parameters
        %init_parameters = 6;
        explorationRate =0.1;%[0, 1]
        niter = 80;  %number of generations
        fitness = @fitness7;

        %% FITNESS PARAMETERS

        %%%EOF
    otherwise
        warning('Unexpected control method')
end

%% DO NOT CHANGE THIS PART!

% backup data
rawTextFromStorage = fileread(which(mfilename));
rawTextFromStorage = regexp(rawTextFromStorage,['%%%;;' '(.*?)%%%EOF'],'match','once');

% join the general static parameter with the particular static one
%rawTextFromStorage = strcat(rawTextFromStorage,rawTextFromStoragePart);
