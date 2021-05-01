using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB3
{
    class Program
    {
        static void Main(string[] args)
        {
            var t1 = new Teacher();
            var s1 = new Student(t1);
            s1.SetRating();
            
            s1.ChoiceOfTopic();
            s1.SetAlgorithmNumber();
            s1.GetAppraisal();
            s1.FileWrite(t1);

        }
    }
}
