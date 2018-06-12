
%%***************************************************
%% Task dependent evaluation function
%%***************************************************


%% 
%data2save             this is a structure used to collect data for visualization or debugging purposes



function [performance, succeeded, data2save] = EvaluateCMAES(obj,action,cur_candidates_index,ismean)
%%
%% action is a row vector where each element denotes the amplitude of one
%% Gaussian Kernel
%%
%% performance denotes the mean squared error to the one dimensional
%% target function

    % i have to assign the variable to avoid error generation
    data2save = [];

    %try
        %disp('i am in evaluate CMAES')
        %action
        
        [run_flag,performance,action]=obj.preprocessing(obj,action);
        % if run flag is true the preprocessing phase states that the
        % candidate is valid
        if(run_flag)
            [output]=obj.run(action);

            succeeded = 1;

            %tic
            % insert fitness function 
            
            
            %toc
            %% i check the eventual fail
            if(nargout(obj.fitness) > 1)
                % here i checked 
                [performance,variable_output] = feval(obj.fitness,obj,output);
                fail_flag = variable_output(1);
            else
                % if the function has no varargout i assume that 
                % i do not have any fails
                 [performance] = feval(obj.fitness,obj,output);
                fail_flag = false;
            end
            %% DO NOT CHANGE THIS PART!
            if(obj.constraints)
               
               if(~fail_flag)
                    % here i compute the final penalty value for each candidate of the
                    % current population
                    obj.penalty_handling.ComputeConstraintsViolation(cur_candidates_index)
               else
                    % here if i ahve an internal i may not want to 
                    obj.penalty_handling.feasibility_vec = ones(size(obj.penalty_handling.feasibility_vec));
               end
               if(cur_candidates_index < 0)
                  % here im going to save the average performance without correction
                  data2save.performance = performance;
                  % perfomance with correction
                  performance = performance - obj.penalty_handling.fitness_penalties(1);
               end
            end
        else
            succeeded = 0;
        end
        %%

        % cancel all the information relative to the current iteration (control action)
        feval(obj.clean_function,obj);

%     catch err
%          %disp('i am in evaluate CMAES error side')
%          % cancel all the information relative to the current iteration (control action)
%          feval(obj.clean_function,obj,'fake_input');
%          succeeded = 0;
%          %% TODO the perfomance penalty related to integration error has to 
%          %% be tuned in relationship of the computation strategy adopted for the fitness 
%          %% (is fitness is not between zero and 1 because of penalty integration error penalty has to be adjusted as well)
%          performance = -1;
%          % here im going to save the average perfomance without correction
%          data2save.performance = performance;
%          disp('error state during the integration in EvaluateCmaes');
%          %rethrow(err);
%     end


end
