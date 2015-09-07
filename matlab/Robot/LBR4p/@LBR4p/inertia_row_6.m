function Irow = inertia_row_6(rob,in2)
%% INERTIA_ROW_6 - Computation of the robot specific inertia matrix row for corresponding to joint 6 of 7. 
% ========================================================================= 
%    
%    Irow = inertia_row_6(rob,q) 
%    Irow = rob.inertia_row_6(q) 
%    
%  Description:: 
%    Given a full set of joint variables this function computes the 
%    inertia matrix row number 6 of 7 for LBR4p copy. 
%    
%  Input:: 
%    rob: robot object of LBR4p copy specific class 
%    q:  7-element vector of generalized 
%         coordinates 
%    Angles have to be given in radians! 
%    
%  Output:: 
%    Irow:  [1x7] row of the robot inertia matrix 
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
%  See also coriolis.
%    
    
% Copyright (C) 1993-2015, by Peter I. Corke 
% Copyright (C) 2012-2015, by Joern Malzahn 
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
   




%    This function was generated by the Symbolic Math Toolbox version 6.1.
%    05-Aug-2015 00:19:29

q2 = in2(:,2);
q3 = in2(:,3);
q4 = in2(:,4);
q5 = in2(:,5);
q6 = in2(:,6);
t2 = cos(q2);
t3 = cos(q4);
t4 = cos(q5);
t5 = cos(q6);
t6 = sin(q4);
t7 = sin(q2);
t8 = sin(q5);
t9 = cos(q3);
t10 = sin(q3);
t11 = sin(q6);
Irow = [t2.*t3.*t5.*(-7.0080888787e-5)+t2.*t3.*t11.*2.46312607e-6+t2.*t6.*t8.*9.134489670485e-3+t4.*t7.*t10.*9.134489670485e-3+t2.*t4.*t5.*t6.*2.46312607e-6+t2.*t5.*t6.*t8.*1.3172328e-2+t2.*t4.*t6.*t11.*7.0080888787e-5+t4.*t5.*t7.*t10.*1.3172328e-2+t2.*t6.*t8.*t11.*1.61616e-4+t3.*t7.*t8.*t9.*9.134489670485e-3+t5.*t6.*t7.*t9.*7.0080888787e-5+t5.*t6.*t7.*t10.*1.6576e-4+t5.*t7.*t8.*t9.*1.351008e-2-t5.*t7.*t8.*t10.*2.46312607e-6+t4.*t7.*t10.*t11.*1.61616e-4-t6.*t7.*t9.*t11.*2.46312607e-6-t6.*t7.*t10.*t11.*1.351008e-2+t7.*t8.*t9.*t11.*1.6576e-4-t7.*t8.*t10.*t11.*7.0080888787e-5+t3.*t4.*t5.*t7.*t9.*2.46312607e-6+t3.*t4.*t5.*t7.*t10.*1.351008e-2+t3.*t5.*t7.*t8.*t9.*1.3172328e-2+t3.*t4.*t7.*t9.*t11.*7.0080888787e-5+t3.*t4.*t7.*t10.*t11.*1.6576e-4+t3.*t7.*t8.*t9.*t11.*1.61616e-4,t9.*(t4.*1.185724550509452e44+t4.*t5.*1.709865932349759e44+t5.*t6.*2.151687818176833e42-t5.*t8.*3.197320438859059e40+t4.*t11.*2.097895622722412e42-t6.*t11.*1.753708648563855e44-t8.*t11.*9.097019467301719e41+t3.*t4.*t5.*1.753708648563855e44+t3.*t4.*t11.*2.151687818176833e42).*7.703719777548943e-47-t10.*(t3.*t8.*9.134489670485e-3+t5.*t6.*7.0080888787e-5+t5.*t8.*1.351008e-2-t6.*t11.*2.46312607e-6+t8.*t11.*1.6576e-4+t3.*t4.*t5.*2.46312607e-6+t3.*t5.*t8.*1.3172328e-2+t3.*t4.*t11.*7.0080888787e-5+t3.*t8.*t11.*1.61616e-4),t3.*t5.*(-7.0080888787e-5)+t3.*t11.*2.46312607e-6+t6.*t8.*9.134489670485e-3+t4.*t5.*t6.*2.46312607e-6+t5.*t6.*t8.*1.3172328e-2+t4.*t6.*t11.*7.0080888787e-5+t6.*t8.*t11.*1.61616e-4,t4.*9.134489670485e-3+t4.*t5.*1.3172328e-2-t5.*t8.*2.46312607e-6+t4.*t11.*1.61616e-4-t8.*t11.*7.0080888787e-5,t5.*(-7.0080888787e-5)+t11.*2.46312607e-6,2.03198995338485e-1,0.0];
