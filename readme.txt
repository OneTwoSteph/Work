GOAL

The goal of my work was to find a control algorithm for a differential wheeled robot in order for it to follow a path given by a collection of points. Those points can of course be chosen or be the result of a path planning algorithm. The initial idea was to implement and test the algorithms at different levels:

	1. Matlab (simple implementation): understand the algorithm;
	2. Simulink with the robot simulator Sim.I.Am.: apply the algorithm to a modeled differential wheeled robot (Sim.I.Am);
	3. Bluetooth: apply the algorithm to real robot by bluetooth from Matlab using the simulink model of step 2;
	4. Implementation: implement the algorithm on the robot directly.

My work was based on the previous work of Miguel Ruiz (you can find all his original documentation and code in the folder "Miguel Ruiz"). He found three different possible controllers and was able to achieve steps 1-2 for them.


WHAT I DID

Before working with the real robot, I did some researches to understand the work of Miguel Ruiz. In that aim, established the dynamics model of a differential wheeled robot, in case we would like to enhance the final controller by taking the dynamics of the robot in account. In fact, that was one of the direction Miguel started to explore but couldn't finish.

After that, we decided to apply step 3 to the three controllers of Miguel. In order to do that, we tried to established the bluetooth connection with the robot. Already existent sketches (Arduino) for the motor control board were used and slightly modified to be able to send commands to the motor and receive information from their encoders. In fact, since the localization part of the robot's software was done by another group, we chose to use simple odometry to test the controllers (this will of course not be the case for the end product, which will use a more elaborated localization method).

After an incident with the robot (boards burned), I dedicated my time to find other algorithms to control the robot, since the robot was out of usage. I found several possibilities in literature and tried to implement one on Matlab and Simulink. I always first implemented the algorithms allowing the robot to reach a certain goal point only and then implemented the slightly adapted algorithm for the robot to follow a sequence of points  (path).

The next section will detail what files and documentation you can find in this folder regarding my work. The code should have enough comments for you to understand it. If it is not the case, I invite you to contact me at stephanie.amati@gmail.com.


NOTE

All the simulation on simulink using Sim.I.Am can run only on Matlab R2012b because Sim.I.Am was created on this version and causes errors on later versions.


FOLDER AND FILES

Arduino sketches: 
Contains sketches for serial communication with the robot's motors that is to say to send commands to them and to receive the values of their encoders. 

The motors of the robot are controlled with a special board called Sabertooth. A second board was added on top of Sabertooth called Kangaroo which converts simple position or speed commands to commands that are "readable" by Sabertooth. The sketches of this folder are for an Arduino connected to the Kangaroo board. The documentation of those boards can be found in the folder "Robot doc".

Here is the list of sketches contained in the folder:
	- commands: sketch to command motor speeds through the terminal;
	- commands_altsofserial: same as commands but using another serial communcation class (Alternative Software Serial, see below);
	- kangaroo: sketch combining the sketches commands and odometry (kangaroo is the name of the board preceding the motor board, see documentation for more informations);
	- kangaroo_matlab: beginning of a sketch which would be able to communicate with the Matlab Simulink models via bluetooth but unfinished and untested;
	- libraries: contains an Arduino library to add to be able to compile the Arduino sketches. In fact, another class was used for serial communication, instead of the built in "Software Serial", which is named "Alternative Software Serial" (https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html). The library should maybe be reinstalled from the Arduino software to work correctly, that can be done with the AltSoftSerial.zip that is the same folder;
	- nothing: does nothing, allows to stop the motors while working on other sketches;
	- odometry: sketch computing the robot's odometry by requesting the motors enconders values;
	- odometry_artsofserial: same as odometry sketch but using Alternative Software Serial.

One important parameter in all the sketches is the number of ticks per revolution of the motors encoders. The encoders have a total of 16 counts per revolution (two channels A and B and only up or down edge counting). The motors are equipped with a gear allowing to enhance the resolution of the encoders since the ratio is 30:1. This means that the number of ticks per motor revolution is equal to 480.

Be aware that this number of ticks represent one revolution of the motors and not one revolution of the robot's wheels since there is an additional gear on the robot of ratio more or less 2.5:1 (to confirm).

The baud rate is currently set to 9600 in the motor boards but needs to be enhanced !

MIGUEL_RUIZ: 
All files from Miguel Ruiz's work (untouched), just in case. There is also a README in this folder.

Literature : 
Contains all the literature I found interesting for the project.

Matlab bluetooth:

Matlab path following:


Miguel Matlab:
Contains Miguel's Matlab code with additional comments and slight changes. 

Robot doc:
Contains documentation about the Kangaroo and Sabertooth boards of the robot (used for the Arduino sketches).