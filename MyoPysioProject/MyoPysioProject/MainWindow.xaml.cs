using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
//using Thalmic.Myo;


namespace MyoPysioProject
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        Student student = new Student();
        public MainWindow()
        {
            InitializeComponent();
            this.statusText.DataContext = student;

            student.StudentName = "hello";
        }

        public class Student
        {
            private string studentname;
            public string StudentName
            {
                get
                {
                    return studentname;
                }
                set
                {
                    studentname = value;
                }
            }
        }
        public void WriteToText() {
            
            this.statusText.Text = "hello";
        }

        private void DrawPicture() {
            //this.picCanvas.Background = "hello";
        }


        private void ExerciseListChange(object sender, SelectionChangedEventArgs e)
        {
            ListBox item = (ListBox)sender;
            
            this.statusText.Text = item.SelectedItem.ToString();
            
        }

        private void startTestButton_Click(object sender, RoutedEventArgs e)
        {

        }

        /*private void ChangeTitleBlock(TextBlock block, ) {
            block.Text = text;
        }*/

       

        
    }
}
