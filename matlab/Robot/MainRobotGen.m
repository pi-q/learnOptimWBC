%% Getting started with symbolics and code generation
% This is a brief example about how we can derive symbolic robot model 
% expressions and how we can generate robot specific functions as well as 
% real-time capable Simulink blocks using the |CodeGenerator| class. The
% example uses a reduced version of the Puma 560 arm with the first 3
% links.
%
% A requirement for this demo is that we have the Mathworks Symbolic Toolbox
% installed besides the Robotics Toolbox.
%

%% Instantiate a |CodeGenerator| class object
% We start off with the instantiation of a |CodeGenerator| class object.
% First, we load the |SerialLink| object for which we intend to generate
% code.
rob = 

%%
% After that, we find a |SerialLink| object named p3 in the workspace. This
% object is used to instantiate the CodeGenerator.
cGen = CodeGenerator(rob)

%% Code generation 
% By default |CodeGenerator| class objects are configured to generate:
%
% * symbolic expressions
% * m-code 
% * Simulink blocks
%
% and they document the CodeGeneration progress on the Matlab console. 
% We may modify this behaviour by passing extra arguments to the
% |CodeGenerator| constructor. (Type |help CodeGenerator| for details)
%
% Now let's generate code for the forward kinematics of our reduced Puma
% 560.
symExp = cGen.genfkine

%%
% The text output to the console may be disabled 
cGen.verbose = false;
%
% or logged to disk by specifying a log file name
cGen.logfile = 'roblog.txt'

%%
% The difference is that in addition the functional output the symbolic
% expression has now been saved to disk along with the generated m-code and
% Simulink blocks. The storage directory is given in |cGen.basepath|, which
% we now add to our search path.
addpath(cGen.basepath)
ls(cGen.basepath)
%%
% The m-code is contained in a specialized robot class.
ls(cGen.robjpath)

%%
% With the generic version of the fkine function from the |SerialLink| 
% class we would compute the forward kinematics as follows:
tic; Tz1 = p3.fkine(qz); t1 = toc
%% 
% In order to use the generated robot specific m-functions we add them to
% the search path and instantiate a new robot object.
addpath(cGen.basepath)
specRob = eval(cGen.getrobfname)
tic; Tz2 = specRob.fkine(qz); t2 = toc

%% Speedup
% The specialized robot version of fkine runs a little faster
% because it only performs the computations necessary for the specific robot.
% The speedup of the generated robot specific m-code becomes even more appearent if we 
% repeat the comparison of the execution times for dynamics
% functions such as:
%
% * gravload -> cGen.gengravload
% * inertia  -> cGen.geninertia
% * coriolis -> cGen.gencoriolis
% * invdyn   -> cGen.geninvdyn
%
% This way the specialized m-code can be used to decrease simulation times.
%
%%
% We obtain the exact solution without floating point notation if we use
% the symbolic expression as follows:
tic; Tz1 = subs(symExp, {'q1', 'q2', 'q3'},qz); toc
%%
% This is however more time consuming. Most probably we might use the
% symbolic expressions for algorithm development, controller design, 
% stability proofs as well as analysis, system identification or teaching. 
%
% It is also possible to get the symbolic expressions for the homogenous
% transformations of up to each individual joint. This has been found to be
% useful for example for during derivation of analytical inverse kinematics
% solutions. See the documentation of genfkine for details.
%

%% C-Code generation
% Since Release 9.9 the RTB is able to also generate ready to use C-code.
% You can enable C-code generation by activating the CodeGenerator property
% flag |cGen.genccode|:
cGen.genccode = true;
%% 
% Now all higher level generator methods (|cGen.genfkine|, |cGen.geninvdyn|
% etc. ...) also produce .c and .h files. They are written to the directory 
% specified by the |cGen.ccodepath| property. You can use the C-files in 
% your projects outside the MATLAB world. The header files are documented
% and compatible with Doxygen.
%
% Instead of using the higher level generator methods, you can also
% directly call the C-code generation routine for the model code of your
% choice. In the following we complement the previously generated m-functions 
% for the forward kinematics by their C-equivalent:
cGen.genccodefkine;
disp('Generated C-headers:')
ls(fullfile(cGen.ccodepath,'include'))
disp('Generated C-definitions:')
ls(fullfile(cGen.ccodepath,'src'))

%% Generating C-MEX functions
% We can use the generated C-code outside the MATLAB world and use it in
% arbitrary C-applications. In addition we can also benefit from it inside
% the MATLAB world by means of C-MEX functions. The automated generation of 
% C-MEX functions is controlled by the CodeGenerator flag properties
% |cGen.genmex| and |cGen.compilemex|: 
cGen.genmex = true;
%%
% Nevhertheless, we can create the C-MEX code for the forward kinematics 
% and inspect the |cGen.robjpath| directory:
cGen.genmexfkine
disp('Robot object directory with new MEX source file fkine.c:')
ls(cGen.robjpath)
%%
% The readily compiled MEX functions will shadow the previously generated
% m-functions. The function calls as such remain identical. Using the
% specialized robot object with MEX files we experience an additional and 
% substantial computation speed up compared to the robot specific m-code 
% as well as the generic rne functions (both, m and MEX version). 
% 

%% Inheritance
% Even though we have not yet generated robot specific code for |SerialLink|
% metods other than |fkine|, we can still use all functionality of
% |SerialLink| objects with our new specialized robot object which inherits
% from |SerialLink|.
J01 = p3.jacob0(qz)
J02 = specRob.jacob0(qz)

%% A look at the generated Simulink blocks
% The Simulink blocks are stored in a Simulink library file. By opening the
% generated Simulink library we can investigate the already optimized robot 
% specific code within the blocks.
% The usage of these blocks is also accompanied with a noticable speedup 
% compared to the blocks based on generic |SerialLink| objects.
eval(cGen.slib);
snapnow;
%%
% Beyond the speedup for simulations all blocks in the generated library
% may be directly compiled for real-time operating systems such as xPC-Target or
% dSpace systems for model based control of real hardware setups.
% This way we avoid tedious and error prone reimplementation of the model 
% on the target hardware.
%
% bdclose(cGen.slib);
