using System;
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

            Console.WriteLine("Round 1: FIGHT");
            Console.WriteLine("Press enter to Quit");
            Console.ReadLine();
        }
    }
}
