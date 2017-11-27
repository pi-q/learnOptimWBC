function plot(obj,chi,params, varargin)
%% plot
% Plot on the current figure (which is supposed to be the scene) the
%   successive positions of the iCub according to the matrix chi
%   Arguments :
%       chi   - matrix of the base + joints positions on one dimension and
%               the time steps on the other dimension
%      params - Structure of all needed parameters
%     'movie' - Option allowing to save each figure as images in order to
%               make a video
%        path - If in movie mode it is the path where to save the images
%  'slowmode' - Activate the slowmode where you have to click on the figure
%               in order to display the next time step
%          fc - If in slowmode you also passe the contact forces vector fc
%               it will also diplay on an other figure the support convex
%               hull and the center of pressures

params.movie = false;
params.slowmode = false;
params.moviepath = [];
ndof  = obj.ndof;

% i check if any option are set for the current plot
if ~(isempty(varargin))
    if strcmp(varargin(1),'movie')
        params.movie = true;
        params.moviepath = varargin(2);
    end
    if strcmp(varargin(1),'slowmode')
        params.slowmode = true;
    end
    if length(varargin) == 2
        params.fc = varargin(2);
    else
        params.fc = [];
    end
end


params.plot_objs{1} = plot3(0,0,0,'.');
axis([-1.2 1.2 -1 1 0 1.2]);
%axis equal
hold on

patch([-0.45 -0.45 0.45 0.45],[-0.53 0.37 0.37 -0.53],[0 0 0 0],[0.6 0.6 0.8]);

%campos([5.1705   -8.3894    6.4718])%([10.3675    4.9702    4.4582]);
%set(gca,'CameraViewAngle',7.8687);
set(gca,'Color',[0.8 0.8 0.8]);
set(gca,'XColor',[0.8 0.8 0.8]);
set(gca,'YColor',[0.8 0.8 0.8]);
set(gca,'ZColor',[0.8 0.8 0.8]);
set(gca,'ydir','reverse')
set(gca,'xdir','reverse')
%set(gca, 'drawmode', 'fast');
set(gcf, 'Position', get(0, 'Screensize'));
rotate3d(gca,'on');

% CoM trajectory
% x_b   = chi(:,1:3);
% qt_b  = chi(:,4:7);
% qj    = chi(:,8:8 + obj.ndof - 1);

%visualizeForwardDynamics(obj,[x_b,qt_b,qj],params)

%end

%function visualizeForwardDynamics(obj,chi,params)

%% Setup visualization
n       = size(chi,1);   % number of instances of the simulation results
qb      = chi(:,1:7);    % first 3 elements provide the position and next 4 elements provide the orientation of the base
qj      = chi(:,8:8 + obj.ndof - 1 );   % joint positions

vis_speed = 1;         % this variable is set to change the visualization speed,
% to make its speed close to the real time in case
% the simulation time step is changed.
alpha = 0.3; %patches transparency

n_joint = length(obj.jointList); % number of points to be plotted (virtual joints)
n_lin = length(obj.linkList); % number of lines to be plotted (virtual links)


% build the adjacency matrix given the name of the links and the
% information stored in the joints structure (we keep also the info if the
% joint is revolute = 1, prismatic joint = 2; fixed = 3 and 0 is equal no connection);
A = zeros(n_joint,n_joint);
for i = 1:n_joint
    search_string = obj.linkList{i};
    for j = 1:length(obj.jointList)
        if(strcmp(obj.jointList{j}.child.Attributes.link,search_string))
            connection_string = obj.jointList{j}.parent.Attributes.link;
            type_of_connection = obj.jointList{j}.Attributes.type;
            index = find(SubStrFind(connection_string, obj.linkList),1);
            if(strcmp(type_of_connection,'revolute'))
                A(i,index) = 1;
            elseif(strcmp(type_of_connection,'prismatic'))
                A(i,index) = 2;
            elseif(strcmp(type_of_connection,'fixed'))
                A(i,index) = 3;
            end
        end
    end
end

% visualization axis
xaxis = 'xdata';
yaxis = 'ydata';
zaxis = 'zdata';

kin = zeros(size(chi,1),7,n_joint);

for jj=1:n_joint
    for ii=1:n % at each instance
        % convert base state to rotation
        [x_b,R_b]    = WBM.utilities.tfms.frame2posRotm(squeeze(qb(ii,:)'));
        %wbm_setWorldFrame(R_b,x_b,[0,0,-9.81]'); %is this needed ??????
        kin(ii,:,jj)   = (wbm_forwardKinematics(R_b,x_b,qj(ii,:)',obj.linkList{jj}))';  % forward kinematics for the list of joints/links
    end
end

kin(:,:,1) = qb; % use base data instead of fwdKin rootlink

drawnow
%% INITIAL PLOTS

% allocate memory
x        = zeros(1,n_joint);
y        = zeros(1,n_joint);
z        = zeros(1,n_joint);
x_b0     = zeros(1,n_joint);
xyzpairs = zeros(n_lin,6);

% plot the base position
x(1) = kin(1,1,1);
y(1) = kin(1,2,1);
z(1) = kin(1,3,1);

x_b0(1) = plot3(x(1),y(1),z(1),'r*');

% plot the joints

for jj = 2:n_joint-1

    [x_btemp,~] = WBM.utilities.tfms.frame2posRotm(kin(1,:,jj)');
    x(jj)       = x_btemp(1);
    y(jj)       = x_btemp(2);
    z(jj)       = x_btemp(3);

    col         = 'r.';
    x_b0(jj)    = plot3(x(jj),y(jj),z(jj),col,'MarkerSize', 25);

end

% plot the position of the COM
jj = n_joint;

[x_btemp,~] = WBM.utilities.tfms.frame2posRotm(kin(1,:,jj)');
x(jj)   = x_btemp(1);
y(jj)   = x_btemp(2);
z(jj)   = x_btemp(3);

x_b0(jj)    = plot3(x(jj),y(jj),z(jj),'g*');

%% LINKS DEFINITION
% define the pairs between the joints that will form the links
% i build the link connection using the info from the connectivity matrix A
for i = 1:n_joint
    row = zeros(1,6);
    logical_row = A(i,:)>=1;
    [result,index]=find(logical_row,1);
    if(result)
        xyzpairs(i,:) = [x(index)  x(i)  y(index)  y(i)  z(index)  z(i)];
    else
        xyzpairs(i,:) = row;
    end
end

% allocate memory
lin               = zeros(1,n_joint);
lnkpatch          = zeros(1,n_joint);
xyzpatch.vertices = zeros(8,3);
xyzpatch.faces    = zeros(6,4);

%TO DO adapt approximate correclyt the size of the boxes to iCub dimension
mult_patch = ones(n_lin,2);
mult_patch(:,1) = mult_patch(:,1)*0.03;
mult_patch(:,2) = mult_patch(:,2)*0.03;

try
    %legs
    mult_patch(strcmp(obj.linkList,'r_lower_leg'),:) = [0.035 0.03];
    mult_patch(strcmp(obj.linkList,'r_ankle_1'),:) = [0.025 0.03];
    mult_patch(strcmp(obj.linkList,'l_lower_leg'),:) = [0.035 0.03];
    mult_patch(strcmp(obj.linkList,'l_ankle_1'),:) = [0.025 0.03];
    %remove dh_frame and skin frames
    mult_patch(strcmp(obj.linkList,'r_hand_dh_frame'),:) = [0 0];
    mult_patch(strcmp(obj.linkList,'l_forearm_dh_frame'),:) = [0 0];
    mult_patch(strcmp(obj.linkList,'r_forearm_dh_frame'),:) = [0 0];
    mult_patch(strcmp(obj.linkList,'l_hand_dh_frame'),:) = [0 0];
    mult_patch(strcmp(obj.linkList,'r_foot_dh_frame'),:) = [0 0];
    mult_patch(strcmp(obj.linkList,'l_foot_dh_frame'),:) = [0 0];
    mult_patch(strcmp(obj.linkList,'chest_skin_frame'),:) = [0 0];
    %torso
    mult_patch(strcmp(obj.linkList,'r_hip_1'),:) = [0.02 0.02];
    mult_patch(strcmp(obj.linkList,'l_hip_1'),:) = [0.02 0.02];
    mult_patch(strcmp(obj.linkList,'r_shoulder_1'),:) = [0.02 0.02];
    mult_patch(strcmp(obj.linkList,'l_shoulder_1'),:) = [0.02 0.02];
    %arms
    mult_patch(strcmp(obj.linkList,'r_gripper'),:) = [0.01 0.035];
    mult_patch(strcmp(obj.linkList,'r_hand'),:) = [0.01 0.01];
    mult_patch(strcmp(obj.linkList,'r_forearm'),:) = [0.01 0.01];
    mult_patch(strcmp(obj.linkList,'r_shoulder_2'),:) = [0.01 0.01];
    mult_patch(strcmp(obj.linkList,'r_shoulder_3'),:) = [0.01 0.01];

    mult_patch(strcmp(obj.linkList,'r_shoulder_3'),:) = [0.01 0.01];
    mult_patch(strcmp(obj.linkList,'l_shoulder_2'),:) = [0.01 0.01];
    mult_patch(strcmp(obj.linkList,'l_gripper'),:) = [0.01 0.035];
    mult_patch(strcmp(obj.linkList,'l_hand'),:) = [0.01 0.01];
    mult_patch(strcmp(obj.linkList,'l_forearm'),:) = [0.01 0.01];
    %head
    mult_patch(strcmp(obj.linkList,'imu_frame'),:) = [0.05 0.05];
    mult_patch(strcmp(obj.linkList,'head'),:) = [0.01 0.01];
    mult_patch(strcmp(obj.linkList,'neck_2'),:) = [0.02 0.02];
catch err
    disp('The URDF file seems to disrespect name convention or some links are missing in the URDF');
end


% plot the lines depicting the links
for jj=1:n_lin

    lin(jj) = line(xaxis,xyzpairs(jj,1:2),yaxis,xyzpairs(jj,3:4),zaxis,xyzpairs(jj,5:6),'erasemode','normal','linewidth',2,'color','blue');

    % for the patches (to determine the orientation of the patch to be applied to the links)
    vectlnk  = [xyzpairs(jj,2)-xyzpairs(jj,1),xyzpairs(jj,4)-xyzpairs(jj,3),xyzpairs(jj,6)-xyzpairs(jj,5)];
    orthlnk  = null(vectlnk);
    orthlnk1 = mult_patch(jj,1)*orthlnk(:,1);
    orthlnk2 = mult_patch(jj,2)*orthlnk(:,2);

    % offsets in the direction orthogonal to the link
    qq1      =  orthlnk1+orthlnk2;
    qq2      = -orthlnk1+orthlnk2;
    qq3      = -orthlnk1-orthlnk2;
    qq4      =  orthlnk1-orthlnk2;

    % vertices for the patch
    xyzpatch.vertices = [xyzpairs(jj,2)+qq1(1) , xyzpairs(jj,4)+qq1(2) , xyzpairs(jj,6)+qq1(3);
        xyzpairs(jj,2)+qq2(1) , xyzpairs(jj,4)+qq2(2) , xyzpairs(jj,6)+qq2(3);
        xyzpairs(jj,2)+qq3(1) , xyzpairs(jj,4)+qq3(2) , xyzpairs(jj,6)+qq3(3);
        xyzpairs(jj,2)+qq4(1) , xyzpairs(jj,4)+qq4(2) , xyzpairs(jj,6)+qq4(3);
        xyzpairs(jj,1)+qq1(1) , xyzpairs(jj,3)+qq1(2) , xyzpairs(jj,5)+qq1(3);
        xyzpairs(jj,1)+qq2(1) , xyzpairs(jj,3)+qq2(2) , xyzpairs(jj,5)+qq2(3);
        xyzpairs(jj,1)+qq3(1) , xyzpairs(jj,3)+qq3(2) , xyzpairs(jj,5)+qq3(3);
        xyzpairs(jj,1)+qq4(1) , xyzpairs(jj,3)+qq4(2) , xyzpairs(jj,5)+qq4(3)];


    xyzpatch.faces   = [ 1 2 3 4;
        1 4 8 5;
        5 8 7 6;
        7 3 2 6;
        2 6 5 1;
        3 7 8 4];

    lnkpatch(jj) = patch('vertices',xyzpatch.vertices,'faces',xyzpatch.faces,'FaceAlpha',alpha);
end

% right foot patch
jj=n_lin+1;

orthlnk1 = [0 0.03 0]';
orthlnk2 = [0 0 0.03]';

qq1 =  orthlnk1+2*orthlnk2;
qq2 = -orthlnk1+2*orthlnk2;
qq3 = -orthlnk1-orthlnk2;
qq4 =  orthlnk1-orthlnk2;

r_foot_index = find(strcmp(obj.linkList,'r_foot'));

xyzpatch.vertices = [xyzpairs(r_foot_index,2)+qq1(1)      , xyzpairs(r_foot_index,4)+qq1(2) , xyzpairs(r_foot_index,6)+qq1(3);
    xyzpairs(r_foot_index,2)+qq2(1)      , xyzpairs(r_foot_index,4)+qq2(2) , xyzpairs(r_foot_index,6)+qq2(3);
    xyzpairs(r_foot_index,2)+qq3(1)      , xyzpairs(r_foot_index,4)+qq3(2) , xyzpairs(r_foot_index,6)+qq3(3);
    xyzpairs(r_foot_index,2)+qq4(1)      , xyzpairs(r_foot_index,4)+qq4(2) , xyzpairs(r_foot_index,6)+qq4(3);
    xyzpairs(r_foot_index,2)+qq1(1)+0.03 , xyzpairs(r_foot_index,4)+qq1(2) , xyzpairs(r_foot_index,6)+qq1(3);
    xyzpairs(r_foot_index,2)+qq2(1)+0.03 , xyzpairs(r_foot_index,4)+qq2(2) , xyzpairs(r_foot_index,6)+qq2(3);
    xyzpairs(r_foot_index,2)+qq3(1)+0.03 , xyzpairs(r_foot_index,4)+qq3(2) , xyzpairs(r_foot_index,6)+qq3(3);
    xyzpairs(r_foot_index,2)+qq4(1)+0.03 , xyzpairs(r_foot_index,4)+qq4(2) , xyzpairs(r_foot_index,6)+qq4(3)];


lnkpatch(jj)      = patch('vertices',xyzpatch.vertices,'faces',xyzpatch.faces,'FaceAlpha',alpha);

% left foot patch
jj=n_lin+2;

orthlnk1 = [0 0.03 0]';
orthlnk2 = [0 0 0.03]';

qq1 =  orthlnk1+2*orthlnk2;
qq2 = -orthlnk1+2*orthlnk2;
qq3 = -orthlnk1-orthlnk2;
qq4 =  orthlnk1-orthlnk2;

l_foot_index = find(strcmp(obj.linkList,'l_foot'));
xyzpatch.vertices = [xyzpairs(l_foot_index,2)+qq1(1)      , xyzpairs(l_foot_index,4)+qq1(2) , xyzpairs(l_foot_index,6)+qq1(3);
    xyzpairs(l_foot_index,2)+qq2(1)      , xyzpairs(l_foot_index,4)+qq2(2) , xyzpairs(l_foot_index,6)+qq2(3);
    xyzpairs(l_foot_index,2)+qq3(1)      , xyzpairs(l_foot_index,4)+qq3(2) , xyzpairs(l_foot_index,6)+qq3(3);
    xyzpairs(l_foot_index,2)+qq4(1)      , xyzpairs(l_foot_index,4)+qq4(2) , xyzpairs(l_foot_index,6)+qq4(3);
    xyzpairs(l_foot_index,2)+qq1(1)+0.03 , xyzpairs(l_foot_index,4)+qq1(2) , xyzpairs(l_foot_index,6)+qq1(3);
    xyzpairs(l_foot_index,2)+qq2(1)+0.03 , xyzpairs(l_foot_index,4)+qq2(2) , xyzpairs(l_foot_index,6)+qq2(3);
    xyzpairs(l_foot_index,2)+qq3(1)+0.03 , xyzpairs(l_foot_index,4)+qq3(2) , xyzpairs(l_foot_index,6)+qq3(3);
    xyzpairs(l_foot_index,2)+qq4(1)+0.03 , xyzpairs(l_foot_index,4)+qq4(2) , xyzpairs(l_foot_index,6)+qq4(3)];

lnkpatch(jj)      = patch('vertices',xyzpatch.vertices,'faces',xyzpatch.faces,'FaceAlpha',alpha);



% store axes objects' handles to a vector
params.plot_objs{1} = [lnkpatch';lin';x_b0'];
%% UPDATING THE PLOTS
ii=2;
movieframenum = 1;

while ii<n+1   % the visualization instance

    tic;      % visualizer step timer start (to setting the visualizer speed)

    % get the positions for the current instance
    for jj=1:n_joint
        [x_btemp,~] = WBM.utilities.tfms.frame2posRotm(kin(ii,:,jj)');
        x(jj) = x_btemp(1);
        y(jj) = x_btemp(2);
        z(jj) = x_btemp(3);
        set(x_b0(jj),xaxis,x(jj),yaxis,y(jj),zaxis,z(jj));
    end

    %	update the joints positions
    for i = 1:n_joint
        row = zeros(1,6);
        logical_row = A(i,:)>=1;
        [result,index]=find(logical_row,1);
        if(result)
            xyzpairs(i,:) = [x(index)  x(i)  y(index)  y(i)  z(index)  z(i)];
        else
            xyzpairs(i,:) = row;
        end
    end

    % update the lines for the links wrt the new joint positions
    for jj=1:n_lin

        set(lin(jj),xaxis,xyzpairs(jj,1:2),yaxis,xyzpairs(jj,3:4),zaxis,xyzpairs(jj,5:6));

        vectlnk   =  [xyzpairs(jj,2)-xyzpairs(jj,1),xyzpairs(jj,4)-xyzpairs(jj,3),xyzpairs(jj,6)-xyzpairs(jj,5)];
        orthlnk   =  null(vectlnk);
        orthlnk1  =  mult_patch(jj,1)*orthlnk(:,1);
        orthlnk2  =  mult_patch(jj,2)*orthlnk(:,2);
        qq1       =  orthlnk1+orthlnk2;
        qq2       = -orthlnk1+orthlnk2;
        qq3       = -orthlnk1-orthlnk2;
        qq4       =  orthlnk1-orthlnk2;

        xyzpatch.vertices = [xyzpairs(jj,2)+qq1(1) , xyzpairs(jj,4)+qq1(2) , xyzpairs(jj,6)+qq1(3);
            xyzpairs(jj,2)+qq2(1) , xyzpairs(jj,4)+qq2(2) , xyzpairs(jj,6)+qq2(3);
            xyzpairs(jj,2)+qq3(1) , xyzpairs(jj,4)+qq3(2) , xyzpairs(jj,6)+qq3(3);
            xyzpairs(jj,2)+qq4(1) , xyzpairs(jj,4)+qq4(2) , xyzpairs(jj,6)+qq4(3);
            xyzpairs(jj,1)+qq1(1) , xyzpairs(jj,3)+qq1(2) , xyzpairs(jj,5)+qq1(3);
            xyzpairs(jj,1)+qq2(1) , xyzpairs(jj,3)+qq2(2) , xyzpairs(jj,5)+qq2(3);
            xyzpairs(jj,1)+qq3(1) , xyzpairs(jj,3)+qq3(2) , xyzpairs(jj,5)+qq3(3);
            xyzpairs(jj,1)+qq4(1) , xyzpairs(jj,3)+qq4(2) , xyzpairs(jj,5)+qq4(3)];

        set(lnkpatch(jj),'vertices',xyzpatch.vertices);

    end

    % feet patches
    % right foot
    jj=n_lin+1;

    orthlnk1 = [0 0.03 0]';
    orthlnk2 = [0 0 0.03]';

    qq1 =  orthlnk1+2*orthlnk2;
    qq2 = -orthlnk1+2*orthlnk2;
    qq3 = -orthlnk1-orthlnk2;
    qq4 =  orthlnk1-orthlnk2;

    xyzpatch.vertices = [xyzpairs(r_foot_index,2)+qq1(1)      , xyzpairs(r_foot_index,4)+qq1(2) , xyzpairs(r_foot_index,6)+qq1(3);
        xyzpairs(r_foot_index,2)+qq2(1)      , xyzpairs(r_foot_index,4)+qq2(2) , xyzpairs(r_foot_index,6)+qq2(3);
        xyzpairs(r_foot_index,2)+qq3(1)      , xyzpairs(r_foot_index,4)+qq3(2) , xyzpairs(r_foot_index,6)+qq3(3);
        xyzpairs(r_foot_index,2)+qq4(1)      , xyzpairs(r_foot_index,4)+qq4(2) , xyzpairs(r_foot_index,6)+qq4(3);
        xyzpairs(r_foot_index,2)+qq1(1)+0.03 , xyzpairs(r_foot_index,4)+qq1(2) , xyzpairs(r_foot_index,6)+qq1(3);
        xyzpairs(r_foot_index,2)+qq2(1)+0.03 , xyzpairs(r_foot_index,4)+qq2(2) , xyzpairs(r_foot_index,6)+qq2(3);
        xyzpairs(r_foot_index,2)+qq3(1)+0.03 , xyzpairs(r_foot_index,4)+qq3(2) , xyzpairs(r_foot_index,6)+qq3(3);
        xyzpairs(r_foot_index,2)+qq4(1)+0.03 , xyzpairs(r_foot_index,4)+qq4(2) , xyzpairs(r_foot_index,6)+qq4(3)];

    set(lnkpatch(jj),'vertices',xyzpatch.vertices);

    % left foot
    jj=n_lin+2;

    orthlnk1 = [0 0.03 0]';
    orthlnk2 = [0 0 0.03]';

    qq1 =  orthlnk1+2*orthlnk2;
    qq2 = -orthlnk1+2*orthlnk2;
    qq3 = -orthlnk1-orthlnk2;
    qq4 =  orthlnk1-orthlnk2;

    xyzpatch.vertices = [xyzpairs(l_foot_index,2)+qq1(1)      , xyzpairs(l_foot_index,4)+qq1(2) , xyzpairs(l_foot_index,6)+qq1(3);
        xyzpairs(l_foot_index,2)+qq2(1)      , xyzpairs(l_foot_index,4)+qq2(2) , xyzpairs(l_foot_index,6)+qq2(3);
        xyzpairs(l_foot_index,2)+qq3(1)      , xyzpairs(l_foot_index,4)+qq3(2) , xyzpairs(l_foot_index,6)+qq3(3);
        xyzpairs(l_foot_index,2)+qq4(1)      , xyzpairs(l_foot_index,4)+qq4(2) , xyzpairs(l_foot_index,6)+qq4(3);
        xyzpairs(l_foot_index,2)+qq1(1)+0.03 , xyzpairs(l_foot_index,4)+qq1(2) , xyzpairs(l_foot_index,6)+qq1(3);
        xyzpairs(l_foot_index,2)+qq2(1)+0.03 , xyzpairs(l_foot_index,4)+qq2(2) , xyzpairs(l_foot_index,6)+qq2(3);
        xyzpairs(l_foot_index,2)+qq3(1)+0.03 , xyzpairs(l_foot_index,4)+qq3(2) , xyzpairs(l_foot_index,6)+qq3(3);
        xyzpairs(l_foot_index,2)+qq4(1)+0.03 , xyzpairs(l_foot_index,4)+qq4(2) , xyzpairs(l_foot_index,6)+qq4(3)];

    set(lnkpatch(jj),'vertices',xyzpatch.vertices);

    % end feet patches

    % store axes objects to a vector
    params.plot_objs{1} = [lnkpatch';lin';x_b0'];


    drawnow;

    % to update the visualizer speed to keep it close to real simulation time
    if ~(params.slowmode)
        time_dif = vis_speed*params.sim_step-toc();

        if time_dif>0

            pause(time_dif);
        else

            vis_speed=vis_speed+1;
        end
    else
        vis_speed = 10;
    end

    if params.movie
        % add a frame to the movie
        % write the frame to the movie folder
        path = fullfile(params.moviepath, sprintf('%04d.png', movieframenum));
        saveas(gcf, path{1});
        movieframenum = movieframenum + 1;
    end

    %slow mode
    %you need to click the figure to get the next frame
    if params.slowmode
        if ~(isempty(params.fc))
            convHull = obj.computeSupPoly(params.feet_on_ground,chi(ii-1,:)');
            if ii == 2
                figCvHull = figure;
                title('Support Polygon','FontSize',16)
                axis equal
            end

            CoP(1)      = -params.fc{1}(5,ii-1)/params.fc{1}(3,ii-1);
            CoP(2)      =  params.fc{1}(4,ii-1)/params.fc{1}(3,ii-1);

            if  params.numContacts == 2
                CoP(3)      = -params.fc{1}(11,ii-1)/params.fc{1}(9,ii-1);
                CoP(4)      =  params.fc{1}(10,ii-1)/params.fc{1}(9,ii-1);

                q_cur = chi(ii-1,:);
                [trans, rot] = obj.offlineFkine(q_cur','r_sole');
                temp = [CoP(3), CoP(4), 0]' + trans;
                temp = rot*temp;
                CoP(3) = temp(1);
                CoP(4) = temp(2);
            end

%             convHull.plotConvHull(figCvHull,CoP(1),CoP(2));
%             convHull.plotConvHull(figCvHull,CoP(3),CoP(4));
            convHull.plotConvHull(figCvHull,qb(ii,1),qb(ii,2)); %plot the projection of the floating base)
        end
        waitforbuttonpress
    end

    ii=ii+vis_speed;

    %clear the convex hull figure in order to display the next frame on a
    %clean figure
    if params.slowmode
        if (ii < n +1) %avoid deleting the last frame
            figure(figCvHull);
            hold on
            cla
            title('Support Polygon','FontSize',16)
            axis equal
            hold off
        end
    end
end


end







