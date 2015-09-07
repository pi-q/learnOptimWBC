function F = friction(rob,in2)
%% FRICTION - Joint friction for the LBR4p copy arm. 
% ========================================================================= 
%    
%    F = friction(rob,qd) 
%    F = rob.friction(qd) 
%    
%  Description:: 
%    Given a full set of generalized joint velocities the function 
%    computes the friction forces/torques. 
%    
%  Input:: 
%    rob: robot object of LBR4p copy specific class 
%    qd:  7-element vector of generalized 
%         velocities 
%    Angles have to be given in radians! 
%    
%  Output:: 
%    F:  [7x1] vector of joint friction forces/torques 
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
%  See also gravload.
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
%    05-Aug-2015 00:18:58

qd1 = in2(:,1);
qd2 = in2(:,2);
qd3 = in2(:,3);
qd4 = in2(:,4);
qd5 = in2(:,5);
qd6 = in2(:,6);
qd7 = in2(:,7);
F = [qd1.*(-5.8018217679508)-2.47313845e1,qd2.*(-9.496868641825)-1.358469e1,qd3.*(-3.9804259903722)-7.0892316,qd4.*(-4.11645229697152e-1)-8.5160768e-1,qd5.*(-4.272830209354e-1)-6.6600698e-1,qd6.*(-2.158232532732e-1)-3.0367656e-1,qd7.*(-2.158232532732e-1)-3.0367656e-1];
