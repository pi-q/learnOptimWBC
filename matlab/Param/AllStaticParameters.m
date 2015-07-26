clear all
close all
clc

%%%;;


%% comment
%this file describe a test task for the elastic reference
%
%
%% TYPE OF CONTROLLER 
CONTROLLERTYPE ='UF';   % GHC or UF
%%

%SUBCHAIN PARAMETERS 
subchain1 = [7];
target_link{1} = subchain1;


%% Robot
[bot1] = MdlLBR4p();
robots{1} = bot1;
chains = SubChains(target_link,robots);
%%

% REFERENCE PARAMETERS
% REFERENCE PARAMETERS
traj_type = {'cartesian_x'};
control_type = {'tracking'};
type_of_traj = {'func'};
geometric_path = {'elastic'};
time_law = {'none'};
%parameters first chains
geom_parameters{1,1} = [5 2 1]; 
%geom_parameters{1,2} = [-0.13 0.02 0.72];
%geom_parameters{1,3} = [0 pi/2 0 -pi/2 0 pi/2 0];
dim_of_task{1,1}=[1;1;1]; %dim_of_task{1,2}= [1;1;1]; dim_of_task{1,3}=ones(bot1.n,1);

%% FROM THIS POINT YOU CAN FIND PARAMETERS IN THE STATIC PARAMETERS FILE RELATED TO EACH ALGORITHM 

%%%EOF

switch CONTROLLERTYPE
    case 'UF'
        UF_StaticParameters
    case 'GHC'
        GHC_StaticParameters
    otherwise
        warning('Unexpected control method')
end


%% Name of the file (backup and .mat)
% id specify wich is the backup data that I have to look at. 
% i have to set the name of the robot plus a number equal to the number of experiment for that scenario 
% like bot#.# (where n.i means that the file is reffered to the n-scenario and is the i-th data setting)
% multiple data setting for the same scenario 
id = 'LBR4p12.0';
name_backup = strcat(id,'.m');
%namebot_scene#_briefdescription.mat
name_file = 'scene0_UF_test_elastic_reference';
name_file = strcat(id,'_',name_file,'.mat');

%% DO NOT CHANGE THIS PART!
% build the correct path for .mat
allpath=which('FindData.m');
path=fileparts(allpath);
save(strcat(path,'/datamat/',name_file));

% backup data 
rawTextFromStorage = fileread(which(mfilename));
rawTextFromStorage = regexp(rawTextFromStorage,['%%%;;' '(.*?)%%%EOF'],'match','once');

% join the general static parameter with the particular static one
rawTextFromStorage = strcat(rawTextFromStorage,rawTextFromStoragePart);

existence = exist(strcat(path,'/back_data/',name_backup),'file');
if(~existence)
    fileID = fopen(strcat(path,'/back_data/',name_backup),'w');
    fprintf(fileID,'%s',rawTextFromStorage);
    fclose(fileID);
    disp('FINISH!')
else
    adv = strcat('The file: /',name_backup,' allready exist');
    b=questdlg(adv, 'Overwrite?','Yes','No','No');
    switch b
        case 'Yes'
            fileID = fopen(strcat(path,'/back_data/',name_backup),'w');
            fprintf(fileID,'%s',rawTextFromStorage);
            fclose(fileID);
            disp('FINISH!')
    end
end


