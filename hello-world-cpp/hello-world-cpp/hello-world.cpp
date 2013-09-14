#include <cmath>
#include <iostream>
#include <myo.h>
#include <fstream>
#include <sstream>   
#include "state.h"

using namespace std;

#include "model.h"
#include "console.h"

static Model model;

void main() {
	Console console;
	model.addObserver(console);
    
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
			if (model.isDetecting()) {
				Move move(motion.orientation().yaw().radians, motion.orientation().pitch().radians, motion.orientation().roll().radians,
					motion.acceleration().x, motion.acceleration().y, motion.acceleration().z,
					motion.angularVelocity().x, motion.angularVelocity().y, motion.angularVelocity().z);
				model.move(move);
			}
	});
	

    //Step 3: Add the listener to the default device
    hub.defaultDevice().addListener(deviceListener);

	int choice;
	do {
		std::cout << "Select exercises" << std::endl;
		std::cout << "1) Exercise A" << std::endl;
		std::cout << "2) Exercise B" << std::endl;
		std::cout << "3) Exit" << std::endl;

		int choice;
		std::cin >> choice;
		switch (choice) {
		case 1:
		case 2:
			runExercise(choice);
			break;
		default:
			break;
		}
	} while (choice != 3);
}

void runExercise(int choice) {
	model.setDetecting(true);
	std::cin.ignore;
	model.setDetecting(false);
}