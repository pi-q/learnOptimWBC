% this class is an interface between the icub robot class and the subchain_class
% we need icub both in DummyRvc_iCub and subchain because we need to compute the overall dynamic and the single kinematic values for each kinematic chain 
classdef DummyRvc_iCub < handle

    properties
        icub             % pointer to the icub structure (to reproduce the same structure of )
        n                % degrees of freedom
        link             % dummy parameter to be compliant with the subchain class
        name             % dummy parameter to be compliant with the subchain class
        model3d          % dummy parameter to be compliant with the subchain class
        tag              % string that represent the kinematic link that i want to control
        
    end
    
    methods
        function obj = DummyRvc_iCub(icub,tag)
            obj.icub = icub;
            obj.link = 'iCub';
            obj.name = 'iCub';
            obj.model3d = 'iCub';
            obj.n = icub.ndof;
            obj.tag = tag;
            
        end   
        
        function T = fkine(obj,q)
            T = obj.icub.fkine(q,obj.tag);
        end
        
        function J0 = jacob0(obj,q,varargin)
            opt.rpy = false;
            opt.eul = false;
            opt.trans = false;
            opt.rot = false;
    
            opt = tb_optparse(opt, varargin);
            J0 = obj.icub.jacob0(q,obj.tag);
            
            if opt.rpy
                rpy = tr2rpy( fkine(obj, q) );
                B = rpy2jac(rpy);
%                 if(~isa(B, 'sym'))
%                    if rcond(B) < eps
%                        disp('Representational singularity');
%                         J0 = blkdiag( eye(3,3), inv(B + 0.01*eye(size(B,1))) ) * J0;
%                    else
%                        J0 = blkdiag( eye(3,3), inv(B) ) * J0;
%                    end
%                 else
                    J0 = blkdiag( eye(3,3), inv(B) ) * J0;
               % end
            elseif opt.eul
                eul = tr2eul( fkine(obj, q) );
                B = eul2jac(eul);
                if rcond(B) < eps
                    error('Representational singularity');
                end
                J0 = blkdiag( eye(3,3), inv(B) ) * J0;
            end

            if opt.trans
                J0 = J0(1:3,:);
            elseif opt.rot
                J0 = J0(4:6,:);
            end
        end

        function J_dot = jacob_dot(obj,q,dq)
            J_dot = obj.icub.jacob_dot(q,dq,obj.tag);
        end 
        % here q is just a dummy variable to be compliant with the
        % structure of my controller because i compute everything in
        % advance inside the icub structure 
        %function M = inertia(obj,q)
        %    M = obj.icub.M;
        %end
        
        
    end

    


end
