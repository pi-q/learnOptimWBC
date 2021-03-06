function Irow = inertia_row_2(rob,in2)
%% INERTIA_ROW_2 - Computation of the robot specific inertia matrix row for corresponding to joint 2 of 6. 
% ========================================================================= 
%    
%    Irow = inertia_row_2(rob,q) 
%    Irow = rob.inertia_row_2(q) 
%    
%  Description:: 
%    Given a full set of joint variables this function computes the 
%    inertia matrix row number 2 of 6 for Puma 560 copy. 
%    
%  Input:: 
%    rob: robot object of Puma 560 copy specific class 
%    q:  6-element vector of generalized 
%         coordinates 
%    Angles have to be given in radians! 
%    
%  Output:: 
%    Irow:  [1x6] row of the robot inertia matrix 
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
    
% Copyright (C) 1993-2014, by Peter I. Corke 
% Copyright (C) 2012-2014, by Joern Malzahn 
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
%    22-Nov-2014 18:28:04

q2 = in2(:,2);
q3 = in2(:,3);
q4 = in2(:,4);
q5 = in2(:,5);
t2 = cos(q2);
t3 = cos(q3);
t4 = sin(q2);
t5 = sin(q3);
t6 = cos(q5);
t7 = sin(q4);
t8 = cos(q4);
t9 = sin(q5);
t10 = t6.^2;
t11 = t8.^2;
t12 = t6.*2.487168e-3;
t13 = t11.*3.0216e-4;
t14 = t10.*2.0216e-4;
Irow = [t2.*(-2.3751e-2)-t4.*6.903913435e-1-t2.*t3.*1.384816665e-1-t2.*t5.*3.80751875e-3-t3.*t4.*3.80751875e-3+t4.*t5.*1.384816665e-1-t2.*t3.*t6.*4.32144e-4+t4.*t5.*t6.*4.32144e-4-t4.*t7.*t9.*1.243584e-3-t2.*t3.*t7.*t9.*1.243584e-3+t2.*t5.*t7.*t8.*3.0216e-4+t3.*t4.*t7.*t8.*3.0216e-4-t2.*t5.*t7.*t9.*5.8464e-5-t3.*t4.*t7.*t9.*5.8464e-5+t2.*t5.*t8.*t9.*4.32144e-4+t3.*t4.*t8.*t9.*4.32144e-4+t4.*t5.*t7.*t9.*1.243584e-3-t2.*t3.*t6.*t7.*t9.*2.0216e-4+t4.*t5.*t6.*t7.*t9.*2.0216e-4-t2.*t5.*t7.*t8.*t10.*2.0216e-4-t3.*t4.*t7.*t8.*t10.*2.0216e-4,t3.*2.191385e-2-t5.*7.69752588e-1+t12+t13+t14-t5.*t6.*2.487168e-3-t8.*t9.*1.16928e-4-t10.*t11.*2.0216e-4-t3.*t8.*t9.*2.487168e-3+4.4319189175,t3.*1.0956925e-2-t5.*3.84876294e-1+t12+t13+t14-t5.*t6.*1.243584e-3-t8.*t9.*1.16928e-4-t10.*t11.*2.0216e-4-t3.*t8.*t9.*1.243584e-3+3.589900705e-1,t7.*t9.*(t5.*-7.7724e4+t6.*1.2635e4+7.7724e4).*(-1.6e-8),t8.*6.4216e-4-t9.*5.8464e-5-t3.*t9.*1.243584e-3+t6.*t8.*1.243584e-3-t5.*t6.*t8.*1.243584e-3,t7.*t9.*4.0e-5];
