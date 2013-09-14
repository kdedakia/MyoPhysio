#include <iostream>
#include <myo.h>

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

	deviceListener.onMotion().add([] (const myo::Motion& motion) {
		//while (true) {
			std::cout << motion.orientation().pitch().degrees();

		//}
	});

    //Step 3: Add the listener to the default device
    hub.defaultDevice().addListener(deviceListener);

    std::cout << "Round 1: FIGHT!" << std::endl;
    std::cout << "Press enter to end";
    std::cin.ignore();
}