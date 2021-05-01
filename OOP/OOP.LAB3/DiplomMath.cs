using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Diagnostics.Eventing.Reader;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB3
{
    public partial class Student
    {
        public string Topic { get; set; }
        public int AlgorithmNumber { get; set; }
        public int Complexity { get; set; }
        public int Appraisal { get; set; }

        public void ChoiceOfTopic()
        {
            Dictionary<int, string> topics = new Dictionary<int, string>(5);
            topics.Add(1,"Тема дипломной работы по программированию: «Автоматизированные информационные системы управления»:");
            topics.Add(2,
                "Тема дипломной работы по программированию: «Предназначение адаптивного матричного мультипликатора");
            topics.Add(3,
                "Тема дипломной работы по программированию: «Адекватность и объективность моделирования информационной системы управления»");
            topics.Add(4,
                "Тема дипломной работы по программированию: «Мониторинговый алгоритм состояния сети передачи данных»");
            topics.Add(5,
                "Тема дипломной работы по программированию: «Сущность и особенности алгоритма работы блока ввода и обработки данных»");
            topics.Add(6,"Тема дипломной работы по программированию: «Оценка интенсивности трафика»");
            topics.Add(7,"Оценка качества связи на основании принятия информационных сигналов");
            
            Console.WriteLine("Topics:");
            foreach (var topic in topics)
            {
                
                Console.WriteLine(topic);
              
            }
            Console.WriteLine("Choice topic:");
            int k = Convert.ToInt32(Console.ReadLine());

            Topic = topics[k];
            Complexity = k;


        }

        public void SetAlgorithmNumber()
        {
            Console.WriteLine("Number of Algorithm");
            int k = Convert.ToInt32(Console.ReadLine());

            AlgorithmNumber = k;
        }
        

        public void GetAppraisal()
        {
            if (AlgorithmNumber != 0 && Topic != null)
            {
                Appraisal = Complexity * AlgorithmNumber;
            }
            else
            {
                Console.WriteLine("You don't have topic or algorithm");
            }
        }

        public Student(string FirstName, string LastName, string Adress, int Passport, int Age, int Telephone, Teacher emp)
        {
            this.FirstName = FirstName;
            this.LastName = LastName;
            this.Adress = Adress;
            this.Passport = Passport;
            this.Age = Age;
            this.Telephone = Telephone;
            Rating = 0;
            emp.NumberOfStudents++;
            emp.WorkHours++;
        }

    }
}
