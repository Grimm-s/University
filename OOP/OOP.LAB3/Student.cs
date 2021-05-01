using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB3
{
    public partial class Student
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Adress { get; set; }
        public int Passport { get; set; }
        public int Age { get; set; }
        public int Telephone { get; set; }
        public double Rating { get; set; }


        public Student(Teacher emp)
        {
            FirstName = null;
            LastName = null;
            Adress = null;
            Passport = 0;
            Age = 0;
            Telephone = 0;
            Rating = 0;
            Topic = null;
            AlgorithmNumber = 0;
            Complexity = 0;
            emp.NumberOfStudents++;
            emp.WorkHours++;
        }

        public void Display()
        {
            Console.WriteLine($"FirstName:{FirstName} LastName:{LastName} Adress:{Adress} Passport:{Passport} Age:{Age} Telephone:{Telephone}");

        }
        public void HandWrite()
        {
            Console.WriteLine("FirstName:");
            FirstName = Console.ReadLine();
            Console.WriteLine("LastName:");
            LastName = Console.ReadLine();
            Console.WriteLine("Adress:");
            Adress = Console.ReadLine();
            Console.WriteLine("Passport:");
            Passport = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Age:");
            Age = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Telephone:");
            Telephone = Convert.ToInt32(Console.ReadLine());
        }
        public void SetRating()
        {
            //List<int> appraisals = new List<int>();
            int Size, Sum = 0, x;
            Console.Write("Size:");
            Size = Convert.ToInt32(Console.ReadLine());
            for (int i = 1; i < Size+1; i++)
            {
                Console.WriteLine("Appraisal "+ i+':');
                x = Convert.ToInt32(Console.ReadLine());
                Sum += x;
                //appraisals.Add(Convert.ToInt32(Console.Read()));
            }
            Rating = Sum / Size;
        }
        public void FileWrite(Teacher emp)
        {
            string path = @"C:\OOP";
            DirectoryInfo dirInfo = new DirectoryInfo(path);
            if (!dirInfo.Exists)
            {
                dirInfo.Create();
            }

            string text = ("Student" + "\n" + "FirstName: " + FirstName + "\t" + "LastName: " + LastName + "\t" + "Adress: " + Adress + "\t" + " Passport: " + Passport + "\t" + " Age: " + Age + "\t" + " Telephone: " + Telephone + "\t" + " Rating: " + Rating + "\n" + "Teacher" + "\n" + "FirstName: " + emp.FirstName + "\t" + "WorkHours: " + emp.WorkHours + "\t" + "AademicDiscipline: " + emp.AademicDiscipline + "\t" + "NumberOfStudents: " + emp.NumberOfStudents 
                           + "\n" + "DiplomTopic: " + Topic + "\n" + "DiplomAppraisal: " + Appraisal + "\t" + "AlgorithmNumber: " + AlgorithmNumber + "\t" + "Complexity: " + Complexity);

            using (FileStream fstream = new FileStream($"{path}\\ Student.txt", FileMode.OpenOrCreate))
            {
                byte[] array = System.Text.Encoding.Default.GetBytes(text);
                fstream.Write(array, 0, array.Length);
                Console.WriteLine("Текст записан в файл");
            }
        }
    }
}

