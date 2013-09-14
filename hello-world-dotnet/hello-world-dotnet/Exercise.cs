using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hello_world_dotnet
{
    class Exercise
    {
        //create the variables that are specific properties for cars
        protected string name = "";
        protected string description = "";
        List<String> instructions = new List<String>();

        protected string [] pictures = new string[5];
        

        //Default constructor
        public Exercise()
        {            
        }
        
        //Overloaded constructor
        public Exercise(string n,string d,string [] p)
        {
            name = n;
            description = d;
            pictures = p;
        }

        
        //Method which displays all of the properties of the exercise
        public static String DisplayInfo()
        {
            return "Name: " + name +
                "\nDescription: " + description +
                "\nPictures: " + pictures;
        }

    }
}
