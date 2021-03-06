% this fitness work with scenario 5, 6, 7
% added controllo sulla torque
function fit = fitness7(obj,t,q)
    global G_OB;
    
    %%%;;
    downsaple = 10;
    L = 1;
    penalty = 5000; %10
    sigma = 0.1; 
    max_effort = 2000;
    max_traj_error = 1000;
    max_penalties  = 20000;
    weight_effort = 1;
    weight_traj_err = 1;
    weight_penal = 5;
    %%%EOF
    contr = obj.controller;
    traj_err= 0;
    repuls  = 0;

    for i=1:downsaple:size(t,2)
        q_cur = q{1}(i,:);
        % compute the trajectory error (absolute error)
        kinematic=CStrCatStr({'contr.subchains.sub_chains{1}.T0_'},num2str(contr.subchains.GetNumSubLinks(1,1)),{'(q_cur)'});
        T = eval(kinematic{1});
        ee = T(1:3,4);
        kinematic=CStrCatStr({'contr.subchains.sub_chains{1}.T0_'},'3',{'(q_cur)'});
        T = eval(kinematic{1});
        elbow = T(1:3,4);
        attr_pos = contr.references.GetTraj(1,1,t(i)); 
        traj_err = traj_err + norm((ee - attr_pos),L);
        % compute the repulsive component for all the obstacle
        for jj=1:size(G_OB,2)
            dist = G_OB(jj).Dist(elbow',L);
            repuls= repuls + penalty*exp(-(dist)/(2*sigma^(2)));
        end
    end
    % max effort
    effort = max(contr.torques{1}(:));
    
    
    % saturations 
    if(effort>max_effort)
       effort = max_effort;
    end
    
    if(repuls>max_penalties)
       repuls = max_penalties;
    end
    
    if(traj_err>max_traj_error)
       traj_err = max_traj_error;
    end
    
    traj_err  = traj_err/max_traj_error;
    repuls = repuls/max_penalties;
    effort = effort/max_effort;
    
    %%DEBUG
    fprintf('traj error is %f\n', traj_err)
    fprintf('repuls term is %f\n', repuls)
    fprintf('effort term is %f\n', effort)
    %---
    fit = (-traj_err*(weight_traj_err) - repuls*(weight_penal) - effort*(weight_effort))*( 1000/(weight_traj_err+weight_penal+weight_effort) );
end