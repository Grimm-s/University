using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB3
{
    public class Teacher
    {
        public string FirstName { get; set; }
        public int WorkHours { get; set; }
        public string AademicDiscipline { get; set; }
        public int NumberOfStudents { get; set; }
        public Teacher()
        {
            FirstName = null;
            WorkHours = 0;
            AademicDiscipline = null;
            NumberOfStudents = 0;

        }
        public Teacher(string FirstName, int WorkHours, string AademicDiscipline)
        {
            this.FirstName = FirstName;
            this.WorkHours = WorkHours;
            this.AademicDiscipline = AademicDiscipline;
           // this.NumberOfStudents = NumberOfStudents;

        }
        public void Display()
        {
            Console.WriteLine($"FirstName:{FirstName} WorkHours:{WorkHours} AademicDiscipline:{AademicDiscipline} NumberOfStudents:{NumberOfStudents}");
        }
        public void HandWrite()
        {
            Console.WriteLine("FirstName:");
            FirstName = Console.ReadLine();
            Console.WriteLine("AademicDiscipline:");
            AademicDiscipline = Console.ReadLine();
            Console.WriteLine("WorkHours:");
            WorkHours = Convert.ToInt32(Console.ReadLine());
            //Console.WriteLine("NumberOfStudents:");
            //NumberOfStudents = Convert.ToInt32(Console.ReadLine());
        } 
        public void FileWrite()
        {
            string path = @"C:\OOP";
            DirectoryInfo dirInfo = new DirectoryInfo(path);
            if (!dirInfo.Exists)
            {
                dirInfo.Create();
            }

            string text = ("FirstName: " + FirstName + "\t"+ "WorkHours: " + WorkHours + "\t" + "AademicDiscipline: "+ AademicDiscipline + "\t" + "NumberOfStudents: "+ NumberOfStudents);

           
            using (FileStream fstream = new FileStream($"{path}\nTeacher.txt", FileMode.Create))
            {              
                byte[] array = System.Text.Encoding.Default.GetBytes(text);
                fstream.Write(array, 0, array.Length);
                Console.WriteLine("Текст записан в файл");
            }
        }
    }


    
}
