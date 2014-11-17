%MDL_PUMA560 Create model of Puma 560 manipulator
%
%      mdl_puma560
%
% Script creates the workspace variable p560 which describes the 
% kinematic and dynamic characteristics of a Unimation Puma 560 manipulator
% using standard DH conventions.
% The model includes armature inertia and gear ratios.
%
% Also define the workspace vectors:
%   qz         zero joint angle configuration
%   qr         vertical 'READY' configuration
%   qstretch   arm is stretched out in the X direction
%   qn         arm is at a nominal non-singular configuration
%
% This file is part of The Robotics Toolbox for MATLAB (RTB).
% 
% RTB is free software: you can redistribute it and/or modify
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



function [LBR4p] = LBR4p(target_link,P)
   clear L
   deg = pi/180;
   % joint angle limits from 
   % A combined optimization method for solving the inverse kinematics problem...
   % Wang & Chen
   % IEEE Trans. RA 7(4) 1991 pp 489-
   L(1) = Revolute('d', 0, 'a', 0, 'alpha', pi/2, ...
       'I', [0, 0.35, 0, 0, 0, 0], ...
       'r', [0, 0, 0], ...
       'm', 0, ...
       'Jm', 200e-6, ...
       'G', -62.6111, ...
       'B', 1.48e-3, ...
       'Tc', [0.395 -0.435], ...
       'qlim', [-160 160]*deg );

   L(2) = Revolute('d', 0, 'a', 0.4318, 'alpha', 0, ...
       'I', [0.13, 0.524, 0.539, 0, 0, 0], ...
       'r', [-0.3638, 0.006, 0.2275], ...
       'm', 17.4, ...
       'Jm', 200e-6, ...
       'G', 107.815, ...
       'B', .817e-3, ...
       'Tc', [0.126 -0.071], ...
       'qlim', [-45 225]*deg );

   L(3) = Revolute('d', 0.15005, 'a', 0.0203, 'alpha', -pi/2,  ...
       'I', [0.066, 0.086, 0.0125, 0, 0, 0], ...
       'r', [-0.0203, -0.0141, 0.070], ...
       'm', 4.8, ...
       'Jm', 200e-6, ...
       'G', -53.7063, ...
       'B', 1.38e-3, ...
       'Tc', [0.132, -0.105], ...
       'qlim', [-225 45]*deg );

   L(4) = Revolute('d', 0.4318, 'a', 0, 'alpha', pi/2,  ...
       'I', [1.8e-3, 1.3e-3, 1.8e-3, 0, 0, 0], ...
       'r', [0, 0.019, 0], ...
       'm', 0.82, ...
       'Jm', 33e-6, ...
       'G', 76.0364, ...
       'B', 71.2e-6, ...
       'Tc', [11.2e-3, -16.9e-3], ...
       'qlim', [-110 170]*deg);

   L(5) = Revolute('d', 0, 'a', 0, 'alpha', -pi/2,  ...
       'I', [0.3e-3, 0.4e-3, 0.3e-3, 0, 0, 0], ...
       'r', [0, 0, 0], ...
       'm', 0.34, ...
       'Jm', 33e-6, ...
       'G', 71.923, ...
       'B', 82.6e-6, ...
       'Tc', [9.26e-3, -14.5e-3], ...
       'qlim', [-100 100]*deg );


   L(6) = Revolute('d', 0, 'a', 0, 'alpha', 0,  ...
       'I', [0.15e-3, 0.15e-3, 0.04e-3, 0, 0, 0], ...
       'r', [0, 0, 0.032], ...
       'm', 0.09, ...
       'Jm', 33e-6, ...
       'G', 76.686, ...
       'B', 36.7e-6, ...
       'Tc', [3.96e-3, -10.5e-3], ...
       'qlim', [-266 266]*deg );

   L(7) = Revolute('d', 0, 'a', 0, 'alpha', 0,  ...
       'I', [0.15e-3, 0.15e-3, 0.04e-3, 0, 0, 0], ...
       'r', [0, 0, 0.032], ...
       'm', 0.09, ...
       'Jm', 33e-6, ...
       'G', 76.686, ...
       'B', 36.7e-6, ...
       'Tc', [3.96e-3, -10.5e-3], ...
       'qlim', [-266 266]*deg );
 
  

    %build the dynamical model of the robot
   LBR4pModel = SerialLink(L, 'name', 'LBR4+', ...
    'manufacturer', 'Kuka', 'comment', 'courtesy of Massimo Cefalo');
   %LBR4pModel.model3d = 'UNIMATE/puma560';
   
   
   %build the subchain struct
   LBR4p = SubChains.BuildSC(target_link,L,P,LBR4pModel,'name', 'LBR4+', ...
       'manufacturer', 'Kuka', 'comment', 'courtesy of Massimo Cefalo');
   %LBR4pModel.model3d = 'UNIMATE/puma560';
   
   
   %
   % some useful poses
   %
   assignin('base', 'qz', [pi/2 0 0 0 0 0]);% zero angles, L shaped pose
   assignin('base', 'qr', [0 pi/2 -pi/2 0 0 0]);% ready pose, arm up
   assignin('base', 'qs', [0 0 -pi/2 0 0 0]);
   assignin('base', 'qn', [0 pi/4 pi 0 pi/4  0]);
   

   clear L
   
end   
