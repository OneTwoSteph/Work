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


FILES

Literature : contains all the literature I found interesting for the project.