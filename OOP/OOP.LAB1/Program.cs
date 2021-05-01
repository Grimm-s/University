using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB1
{
    public class functions
    {
        public static int Function1()
        {
            int a = 1, b = 2, c = 3, d = 4, x1;
            Console.WriteLine("Решить полином p=a*x^5-b*x^4+c*x+d, где a=1, b=2, c=3, d=4");
           
            Console.Write("Введите x:");
            x1 = Convert.ToInt32(Console.ReadLine());
            int result = (int)(a * Math.Pow(x1, 5) - b * Math.Pow(x1, 4) + c * x1 + d);
            Console.Write("Результат:");
            return result;
        }
        public static double Function2()
        {
            int a, b;
            Console.WriteLine("x =(a-b)^0.5/a+|sin(a)/cos(b)|");
            Console.WriteLine("Параметр а должен быть больше b");
            Console.Write("Введите a:");
            a = Convert.ToInt32(Console.ReadLine());
            Console.Write("Введите b:");
            b = Convert.ToInt32(Console.ReadLine());
           
            double result = Math.Sqrt(a - b) / a + Math.Abs(Math.Sin(a) / Math.Cos(b));
            Console.Write("x:");
            return result;
        }
        public static int Function3()
        {
            int result2, x2;
            Console.WriteLine("Найти значение функции:");
            Console.WriteLine("F(x) = x^2+4, x>0");
            Console.WriteLine("F(x)= x-5, x<0");
            Console.WriteLine("F(x)=0, x=0");
            Console.WriteLine("Введите x:");
            x2 = Convert.ToInt32(Console.ReadLine());
            
            if (x2 > 0)
            {
                result2 = x2*x2 + 4;
            }
            else if (x2 < 0)
            {
                result2 = x2 - 5;
            }
            else
            {
                result2 = 0;
            }
            Console.Write("F(x):");
            return result2;
            
        }
        public static void Function4()
        {
            Console.Write("Напишите номер месяца:");
            int x = Convert.ToInt32(Console.ReadLine());
            switch (x)
            {
                case (1):
                    Console.WriteLine("Январь");
                    break;
                case (2):
                    Console.WriteLine("Февраль");
                    break;
                case (3):
                    Console.WriteLine("Март");
                    break;
                case (4):
                    Console.WriteLine("Апрель");
                    break;
                case (5):
                    Console.WriteLine("Май");
                    break;
                case (6):
                    Console.WriteLine("Июнь");
                    break;
                case (7):
                    Console.WriteLine("Июль");
                    break;
                case (8):
                    Console.WriteLine("Август");
                    break;
                case (9):
                    Console.WriteLine("Сентябрь");
                    break;
                case (10):
                    Console.WriteLine("Октябрь");
                    break;
                case (11):
                    Console.WriteLine("Ноябрь");
                    break;
                case (12):
                    Console.WriteLine("Декабрь");
                    break;
                default:
                    Console.WriteLine("Неправильный ввод");
                    break;

            }
        }
        public static double Function5()
        {
            Console.WriteLine("Найти произведение ряда k+1/k, k=1, выбрав количество членов");
            Console.Write("Введите n:");
            int n = Convert.ToInt32(Console.ReadLine());
            int k = 1;
            double sum=1;
            for(int i=0; i < n; i++)
            {
                sum = (sum*(k + 1))/k;
                k++;               
            }
            Console.Write("Sum:");
            return sum;
        }

        class Program
        {
            static void Main(string[] args)
            {
                Console.WriteLine("Рыбак Семён, 18 лет, ИПЗ-11, 1 курс, rsemen2002@gmail.com");
                Console.WriteLine();
                Console.WriteLine(functions.Function1());
                Console.WriteLine();
                Console.WriteLine(functions.Function2());
                Console.WriteLine();
                Console.WriteLine(functions.Function3());              
                Console.WriteLine();
                functions.Function4();
                Console.WriteLine();
                Console.WriteLine(functions.Function5());
                Console.WriteLine();

                Console.ReadKey();
            }
        }
    }
}   
