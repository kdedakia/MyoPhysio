#include <iostream>
#include <myo.h>
#include <fstream>
#include <sstream>   

using namespace std;

void main() {
    
    //Step 1: Create all the things
    myo::Hub hub;
    myo::SimpleDeviceListener deviceListener;

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
	
	myfile.open ("F:\\My Documents\\GitHub\\hashbang-physio\\app\\js\\data.json");
	
	
	static int i = 0;
	static double pitch[1000];
	static double roll[1000];
	static double yaw[1000];
	static int data_cap = 1000;
	static double pitchOffset = 0;
	static double rollOffset = 0;
	static double yawOffset = 0;
	deviceListener.onMotion().add([] (const myo::Motion& motion) {
			std::cout << motion.orientation().pitch().degrees() << endl;
			
			if (i < data_cap) {
				pitch[i] =  motion.orientation().pitch().degrees() + pitchOffset; 
				roll[i] = motion.orientation().roll().degrees() + rollOffset; 
				yaw[i] = motion.orientation().yaw().degrees() + yawOffset;
				if (i > 0) {
					double dp = pitch[i] - pitch[i-1];
					if (dp > 180) {
						pitch[i] -= 360;
						pitchOffset -= 360;
					} else if (dp < -180) {
						pitch[i] += 360;
						pitchOffset += 360;
					}
					double dr = roll[i] - roll[i-1];
					if (dr > 180) {
						roll[i] -= 360;
						rollOffset -= 360;
					} else if (dr < -180) {
						roll[i] += 360;
						rollOffset += 360;
					}
					double dy = yaw[i] - yaw[i-1];
					if (dy > 180) {
						yaw[i] -= 360;
						yawOffset -= 360;
					} else if (dy < -180) {
						yaw[i] += 360;
						yawOffset += 360;
					}
				}
				
				stringstream s;
				s << pitch[i] << "," << roll[i] << "," << yaw[i] << "\n";
				
				//myfile << s.str();

				i += 1;
			}
			else {
				myfile << "{ \"pitch\": [";

				for(int i = 0; i < data_cap; i++) {
					if (i < data_cap -1) {
						myfile << pitch[i] << "," ;
					}
					else {
						myfile << pitch[i];
					}
				}
				myfile << "],\n";

				myfile << "\"roll\": [";

				for(int i = 0; i < data_cap; i++) {
					if (i < data_cap-1) {
						myfile << roll[i] << "," ;
					}
					else {
						myfile << roll[i];
					}
				}
				myfile << "],\n";

				myfile << "\"yaw\": [";

				for(int i = 0; i < data_cap; i++) {
					if (i < data_cap-1) {
						myfile << yaw[i] << "," ;
					}
					else {
						myfile << yaw[i];
					}
				}
				myfile << "]\n}";

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