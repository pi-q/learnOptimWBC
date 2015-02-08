disp('UF_RUNTIMEPARAM')

%%%;;

% REPELLERS PARAMETERS
% GENERALIZE TO MULTICHAIN !!!
rep_obstacle_ref = [1 2]; % if i change the order of ref obstacle i change the order of repellor in the stacked case
J_damp = 0.01;
% with this part i choose if for each repellers i want to use 3 or one
% activation policy if 1 only one if 0 we have three activation policy
single_alpha_chain1 = [1 1];
single_alpha_chain2 = [1];
single_alpha{1} = single_alpha_chain1;
single_alpha{2} = single_alpha_chain2;
type_of_rep_strct={'extended_decoupled' 'extended_combine','stacked' };

%ALPHA PARAMETERS
%rbf
number_of_basis = 10;
redundancy = 3;
value_range = [0 , 12];
precomp_sample = false;
% value of theta that we have to change when we want to execute the result
% from the optimization step
numeric_theta = [3.493783 6.211959 7.883578 11.988846 7.900086 9.468388 6.525209 11.867391 7.355206 8.158990 0.000000 0.054878 11.131856 8.063698 1.871041 9.107188 3.646651 8.656589 11.419753 4.346246 ];  
numeric_theta =[12 12 12 12 12 12 12 12 12 12 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0];
%constant alpha
value1 = 1*ones(chains.GetNumTasks(1));
values{1} = value1;


%CONTROLLER PARAMETERS
max_time = 100; %50
combine_rule = {'projector'}; % sum or projector
% with this term i introduce a damped least square structure inside my
% controller if regularizer is 0 i remove the regularizer action 
regularizer_chain_1 = [0.01 0]; 
regularized_chain_2 = [1];
regularizer{1} = regularizer_chain_1;
regularizer{2} = regularized_chain_2;


% CMAES PARAMETER
% starting value of parameters
%init_parameters = 6;
explorationRate =0.1;%[0, 1]
niter = 80;


%%%EOF

%% DO NOT MODIFY THIS PART 

rawTextFromStoragePart = fileread(which(mfilename));
rawTextFromStoragePart = regexp(rawTextFromStoragePart,['%%%;;' '(.*?)%%%EOF'],'match','once');