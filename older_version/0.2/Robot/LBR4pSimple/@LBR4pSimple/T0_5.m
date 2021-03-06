function T0_5 = T0_5(rob,in2)
%% T0_5 - Forward kinematics for the LBR4pSimple copy arm up to frame 5 of 7. 
% ========================================================================= 
%    
%    T = T0_5(rob,q) 
%    T = rob.T0_5(q) 
%    
%  Description:: 
%    Given a set of joint variables up to joint number 5 the function 
%    computes the pose belonging to that joint with respect to the base frame. 
%    
%  Input:: 
%    q:  5-element vector of generalized coordinates. 
%    Angles have to be given in radians! 
%    
%  Output:: 
%    T:  [4x4] Homogenous transformation matrix relating the pose of joint 5 of 7 
%              for the given joint values to the base frame. 
%    
%  Example:: 
%    --- 
%    
%  Known Bugs:: 
%    --- 
%    
%  TODO:: 
%    --- 
%    
%  References:: 
%    1) Robot Modeling and Control - Spong, Hutchinson, Vidyasagar 
%    2) Modelling and Control of Robot Manipulators - Sciavicco, Siciliano 
%    3) Introduction to Robotics, Mechanics and Control - Craig 
%    4) Modeling, Identification & Control of Robots - Khalil & Dombre 
%    
%  Authors:: 
%    This is an autogenerated function! 
%    Code generator written by: 
%    Joern Malzahn 
%    2012 RST, Technische Universitaet Dortmund, Germany 
%    http://www.rst.e-technik.tu-dortmund.de 
%    
%  See also LBR4pSimple copy.
%    
    
% Copyright (C) 1993-2016, by Peter I. Corke 
% Copyright (C) 2012-2016, by Joern Malzahn 
% 
% This file has been automatically generated with The Robotics Toolbox for Matlab (RTB). 
% 
% RTB and code generated with RTB is free software: you can redistribute it and/or modify 
% it under the terms of the GNU Lesser General Public License as published by 
% the Free Software Foundation, either version 3 of the License, or 
% (at your option) any later version. 
%  
% RTB is distributed in the hope that it will be useful, 
% but WITHOUT ANY WARRANTY; without even the implied warranty of 
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
% GNU Lesser General Public License for more details. 
%  
% You should have received a copy of the GNU Leser General Public License 
% along with RTB.  If not, see <http://www.gnu.org/licenses/>. 
% 
% http://www.petercorke.com 
% 
% The code generation module emerged during the work on a project funded by 
% the German Research Foundation (DFG, BE1569/7-1). The authors gratefully  
% acknowledge the financial support. 

%% Bugfix
%  In some versions the symbolic toolbox writes the constant $pi$ in
%  capital letters. This way autogenerated functions might not work properly.
%  To fix this issue a local variable is introduced:
PI = pi;
   




%    This function was generated by the Symbolic Math Toolbox version 5.10.
%    29-Feb-2016 17:45:50

q1 = in2(:,1);
q2 = in2(:,2);
q3 = in2(:,3);
q4 = in2(:,4);
q5 = in2(:,5);
t2 = cos(q1);
t3 = cos(q3);
t4 = sin(q1);
t5 = cos(q2);
t6 = sin(q3);
t7 = sin(q4);
t8 = t4.*t6;
t13 = t2.*t3.*t5;
t9 = t8-t13;
t10 = cos(q4);
t11 = sin(q2);
t12 = sin(q5);
t14 = t9.*t10;
t15 = t2.*t7.*t11;
t16 = t14+t15;
t17 = cos(q5);
t18 = t3.*t4;
t19 = t2.*t5.*t6;
t20 = t18+t19;
t21 = t2.*t6;
t22 = t3.*t4.*t5;
t23 = t21+t22;
t24 = t10.*t23;
t25 = t24-t4.*t7.*t11;
t26 = t2.*t3;
t27 = t26-t4.*t5.*t6;
t28 = t5.*t7;
t29 = t3.*t10.*t11;
t30 = t28+t29;
T0_5 = reshape([-t12.*t20-t16.*t17,t12.*t27+t17.*t25,-t17.*t30+t6.*t11.*t12,0.0,t7.*t9-t2.*t10.*t11,-t7.*t23-t4.*t10.*t11,-t5.*t10+t3.*t7.*t11,0.0,t12.*t16-t17.*t20,-t12.*t25+t17.*t27,t12.*t30+t6.*t11.*t17,0.0,t2.*t11.*(2.0./5.0)-t7.*t9.*(3.9e1./1.0e2)+t2.*t10.*t11.*(3.9e1./1.0e2),t4.*t11.*(2.0./5.0)+t7.*t23.*(3.9e1./1.0e2)+t4.*t10.*t11.*(3.9e1./1.0e2),t5.*(2.0./5.0)+t5.*t10.*(3.9e1./1.0e2)-t3.*t7.*t11.*(3.9e1./1.0e2)+3.1e1./1.0e2,1.0],[4, 4]);
