#include <iostream>
#include <myo.h>
#include <fstream>
#include <sstream>   
#include "state.h"

using namespace std;

void main() {
    
    //Step 1: Create all the things
    myo::Hub hub;
    myo::SimpleDeviceListener deviceListener;

	State firstState, durationState, lastState;
	State armStretch[3] = {firstState, durationState, lastState};

    //Step 2: Hook up the handlers for the events you care about
    deviceListener.onPoseStart().add([] (const myo::Pose& pose) {
        if (pose.type() == myo::PoseType::FIST) {
            std::cout << "HADO" << std::endl;
        }
    });

    deviceListener.onPoseFinish().add([] (const myo::Pose& pose) {
        if (pose.type() == myo::PoseType::FIST) {
            std::cout << "UKEN" << std::endl;
        }
    });
	
	static ofstream myfile;
	myfile.open ("exercise_data.txt");
	myfile << "Writing this to a file.\n";
	
	static int i = 0;
	static double pitch[1000];
	static double roll[1000];
	static double yaw[1000];

	deviceListener.onMotion().add([] (const myo::Motion& motion) {
			std::cout << motion.orientation().pitch().degrees() << endl;
			
			if (i < 1000) {
				pitch[i] =  motion.orientation().pitch().degrees(); 
				roll[i] = motion.orientation().roll().degrees(); 
				yaw[i] = motion.orientation().yaw().degrees(); 
				
				stringstream s;
				s << pitch[i] << "," << roll[i] << "," << yaw[i] << "\n";
				myfile << s.str();

				i += 1;
			}
			else {
				myfile.close();
				exit(true);
			}
	});
	

    //Step 3: Add the listener to the default device
    hub.defaultDevice().addListener(deviceListener);

    std::cout << "Round 1: FIGHT!" << std::endl;
    std::cout << "Press enter to end";
    std::cin.ignore();
}