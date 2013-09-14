﻿using System;
using Thalmic.Myo;

namespace hello_world_dotnet
{
    class Program
    {
        static void Main(string[] args)
        {
            //Step 1: Create all the things
            Hub hub = new Hub();
            SimpleDeviceListener deviceListener = new SimpleDeviceListener();

            SimpleDeviceListener motionDataListener = new SimpleDeviceListener();

            motionDataListener.PoseStart += (object sender, PoseEventArgs e) => 
            { 
                Quaternion quat;
                quat = hub.DefaultDevice.Motion.Orientation;
            };

            //Step 2: Hook up the handers for the events you care about
            deviceListener.PoseStart += (object sender, PoseEventArgs e) => 
            {
                if (e.Pose.Type == PoseType.Fist)
                {
                    Console.WriteLine("HADO");
                }
            };

            deviceListener.PoseFinish += (object sender, PoseEventArgs e) =>
            {
                if (e.Pose.Type == PoseType.Fist)
                {
                    Console.WriteLine("UKEN");
                }
            };

            //Step 3: Add the listener to the default device
            hub.DefaultDevice.AddListener(deviceListener);
            hub.DefaultDevice.AddListener(motionDataListener);
            Console.WriteLine("Round 1: FIGHT");
            Console.WriteLine("Press enter to Quit");
            Console.ReadLine();
        }

        public static double getDuration(int timeStart, int timeFinish)
        {
            return timeFinish-timeStart;
        }

        public static double angularVelocityMagnitude(int x, int y, int z)
        {
            return Math.Sqrt(Math.Pow(x, 2) + Math.Pow(y, 2) + Math.Pow(z, 2));
        }
    }
 
}