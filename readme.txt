GOAL

The goal of my work was to find a control algorithm for a differential wheeled robot in order for it to follow a path given by a collection of points. Those points can of course be chosen or be the result of a path planning algorithm. The initial idea was to implement and test the algorithms at different levels:

	1. Matlab (simple implementation): understand the algorithm;
	2. Simulink with the robot simulator Sim.I.Am.: apply the algorithm to a modeled differential wheeled robot (Sim.I.Am);
	3. Bluetooth: apply the algorithm to real robot by bluetooth from Matlab using the simulink model of step 2;
	4. Implementation: implement the algorithm on the robot directly.

My work was based on the previous work of Miguel Ruiz (you can find all his original documentation and code in the folder "MIGUEL_RUIZ"). He found three different possible controllers and was able to achieve steps 1-2 for them.


WHAT I DID

Before working with the real robot, I did some researches to understand the work of Miguel Ruiz. In that aim, I established the dynamics model of a differential wheeled robot, in case we would like to enhance the final controller by taking the dynamics of the robot in account. In fact, that was one of the direction Miguel started to explore.

After that, we decided to apply step 3 to the three controllers of Miguel. In order to do that, we tried to established a bluetooth connection with the robot. Already existent sketches (Arduino) for the motor control board were used and slightly modified to be able to send commands to the motor and receive information from their encoders. In fact, since the localization part of the robot's software was done by another group, we chose to use simple odometry to test the controllers (this will of course not be the case for the end product, which will use a more elaborated localization method).

After an incident with the robot (boards burned), I dedicated my time to find other algorithms to control the robot. I found several possibilities in literature and tried to implement one of them on Matlab and Simulink. I always first implemented the algorithms allowing the robot to reach a certain goal point only and then implemented the slightly adapted algorithm for the robot to follow a sequence of points  (path).

The next section will detail what files and documentation you can find in this folder regarding my work. The code should have enough comments for you to understand it. If it is not the case, I invite you to contact me at stephanie.amati@gmail.com.


FOLDER AND FILES

Arduino sketches
Contains sketches for serial communication with the robot's motors that is to say to send commands to them and to receive the values of their encoders. 

The motors of the robot are controlled with a special board called Sabertooth. A second board was added on top of Sabertooth called Kangaroo which converts simple position or speed commands to commands that are "readable" by Sabertooth. The sketches of this folder are for an Arduino connected to the Kangaroo board. The documentation of those boards can be found in the folder "Robot doc".

Here is the list of sketches contained in the folder:
	- commands: sketch to command motor speeds through the terminal;
	- commands_altsofserial: same as commands but using another serial communcation class (Alternative Software Serial, see below);
	- kangaroo: sketch combining the sketches commands and odometry (kangaroo is the name of the board preceding the motor board, see documentation for more informations);
	- kangaroo_matlab: beginning of a sketch which would be able to communicate with the Matlab Simulink models via bluetooth but code unfinished and untested;
	- libraries: contains an Arduino library to add to be able to compile the Arduino sketches. In fact, another class was used for serial communication, instead of the built in "Software Serial", which is named "Alternative Software Serial" (https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html). The library should maybe be reinstalled from the Arduino software to work correctly, that can be done with the AltSoftSerial.zip that is the same folder;
	- nothing: does nothing, allows to stop the motors while working on other sketches;
	- odometry: sketch computing the robot's odometry by requesting the motors enconders values;
	- odometry_artsofserial: same as odometry sketch but using Alternative Software Serial.

One important parameter in all the sketches is the number of ticks per revolution of the motors encoders. The encoders have a total of 16 counts per revolution (two channels A and B and only up or down edge counting). The motors are equipped with a gear allowing to enhance the resolution of the encoders since the ratio is 30:1. This means that the number of ticks per motor revolution is equal to 480.

Be aware that this number of ticks represent one revolution of the motors and not one revolution of the robot's wheels since there is an additional gear on the robot of ratio more or less 2.5:1 (to confirm).

The baud rate is currently set to 9600 in the motor boards but needs to be enhanced !

MIGUEL_RUIZ
All files from Miguel Ruiz's work (untouched), just in case. There is also a README in this folder.

Literature
Contains all the literature used or interesting for the project, sorted by themes:
	- Dynamics model: Contains the two main papers used to establish the dynamics model of the differential wheeled robot and also other papers that could help;
	- Path following and planning: Contains the papers about the path following algorithm I implemented (Canudas) but also a lot of other papers which would be interesting to analyze;
	- Theory: Contains papers or course notes that helped me in the project;

Matlab
Contains all the matlab files used sorted in categories.
	- Bluetooth: Contains two matlab files with the main commands to connect via bluetooth or serial communication to a device (serial_commands.m and bluetooth_commands.m). Contains also the two first Miguel's simulink models (my_demo1.slx and my_demo2.slx) slightly modified to be able to communicate by bluetooth with the actual real robot. The Sim.I.Am special simulink library is also present in the folder because some of its blocks are still used in the models (simiam.mdl and msdfun_uni_t_diff.m). Nevertheless, those models are unfinished and untested and should therefore just be used as a basis for future work. Remember also to execute the m-file param.m before launching simulink models. In fact, it contains some of the parameters used in the models. Finally, the folder contains a word document about serial communication in Matlab;
	- Dynamics: Contains implementations of the dynamics model of the differential wheeled robot (unfinished) based on literature (see reference in files);
	- Miguel: Contains all the original Matlab code from Miguel with additional comments and slight changes. There is also a simple Simulink model of the differential wheeled robot in it;
	- Path following: Contains all the matlab files I wrote to implement the Canudas algorithm. The main file is canudas.m (it also has the references to the paper used) and all the others are slightly modified versions of this one. canudas_path.m is the file containing the modified algorithm for the robot to follow a sequence of points. Nevertherless, this part is not finished and not well tested.

Robot doc
Contains documentation about the Kangaroo and Sabertooth boards of the robot (used for the Arduino sketches).

Simulink Simiam models
Contains all the necessary files for the controllers simulink model using Sim.I.Am simulation. Sim.I.Am original files and doc can be found at http://jpdelacroix.com/simiam/ or http://www.mathworks.com/matlabcentral/fileexchange/40860-sim-i-am. You can also find some doc in the manual folder.

BEFORE DOING ANYTHING: All the simulation on simulink using Sim.I.Am can run only on Matlab R2012b because Sim.I.Am was created on this version and causes errors on later versions. So be sure to run the files on the right Matlab version.

The Sim.I.Am simulation files are in the folder +simiam and the simulink models are all in the simulink folder (Miguel's controllers slightly modified and Canudas controller).

For all models, the m-file param.m should be launched first because it contains all the necessary parameters for the models. It is also in this file that all the parameter changes should be done, for more clarity. Be aware that the robots parameters should be the ones of the Khepera robot and not the ones of the real robot since all the Sim.I.Am implementation was done with the parameters of Khepera (in the files of +simiam). The sample time should also alwas be 0.033s because it is defined like that in the file of +simiam.

Regarding Miguel's controllers, the models called my_demoX.sfx simulate his controllers allowing the robot to reach a goal point as the models called my_demo_refX.sfx simulate the same controllers slightly modified for the robot to follow a sequence of points. For the latter models, the m-file robot_path.m has to be executed before simulating and the initial pose of the robot HAS TO BE [0,0,0]. Furthermore for some reason, those models are not correctly working with the parametrization I did... I am sorry I had not enough time to resolve this ! If you wanna see how this models work, try to launch them from the MIGUEL_RUIZ folder. Nervetheless, in this folder, I think there is a mistake of sample time. In fact, the sample time in the files of +simiam is equal to 0.05s instead of 0.033s.

All the files starting by msfun_... are part of the Sim.I.Am simulator.

There are two models for the canudas controller (canudasX.sfx). Only the controller allowing the robot to reach a given pose was implemented. The model 2 is the basic model of the controller with some scopes to observe the behaviour of the variables. Initial pose and goal pose can be changed in the file param.m.  Model 3 is just a try to enhance the model in order for the controller to check when the motor commands are above the limit commands and do something about it. But the result is bad and should still be investigated.


FURTHER WORK

The present project could be continued by testing and implementing other control algorithms for path following. A few useful algorithms can be found in the literature folder.

The robot should then be repaired in order to eventually continue the work with bluetooth connection and control from Matlab to test the controllers. Nevertheless, this idea should be rethinked because it implies a lot of potential problems as for example the speed of bluetooth communication which would be too slow and also the control loop synchronization between the robot and Simulink.

The final step would then be to test the controllers on the robot by directly implementing them on it and then finally choose the best algorithm to be used. The final algorithm should also be chosen in function of the type of path planning technique that will be used.