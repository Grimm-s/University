using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB3
{
    static class СreativeWork
    {
        public static void Task1()
        {
            Console.Write("N = ");
            int n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Prime numbers up to {0}:", n);
            List<int> numbers = new List<int>();
            for (int i = 2; i < n; i++)
            {
                numbers.Add(i);
            }
            for (int i = 0; i < numbers.Count; i++)
            {
                for (int j = 2; j < n; j++)
                {

                    numbers.Remove((int)(numbers[i] * j));
                }
            }
            foreach (int item in numbers)
            {
                Console.Write(item + " ");
            }
        }
        public static void Task2()
        {
            Console.Write("Введите строку: ");
            string str;
            int index = 0;
            str = Convert.ToString(Console.ReadLine());

            Console.Write("Введите подстроку для удаления: ");

            string substr1 = Console.ReadLine();
            if (str.Contains(substr1))
            {

                int n = str.IndexOf(substr1);
                index = n;
                str = str.Remove(n, substr1.Length);
                Console.Write("Подстрока после удаления: ");
                Console.WriteLine(str);
            }
            else
            {
                Console.WriteLine("Подстрока не найдена");
            }
            Console.Write("Введите подстроку для вставки: ");
            string substr2 = Console.ReadLine();
            str = str.Insert(index, substr2);
            Console.Write("Подстрока после вставки: ");
            Console.WriteLine(str);

        }
        public static void Task3()
        {
            Random aRand = new Random();
            int x, y, xi, yi, xs = 0, ys = 0;
            Console.Write("Select x:");
            x = Convert.ToInt32(Console.ReadLine());
            Console.Write("Select y:");
            y = Convert.ToInt32(Console.ReadLine());
            int[,] massiv = new int[x, y];
            for (int i2 = 0; i2 < y; i2++)
            {
                for (int i1 = 0; i1 < x; i1++)
                {
                    massiv[i1, i2] = aRand.Next(100);
                    Console.Write("{0,5}", massiv[i1, i2]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();
            Console.Write("Select number of row:");
            yi = Convert.ToInt32(Console.ReadLine());
            Console.Write("Select number of column:");
            xi = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < x; i++)
            {
                xs += massiv[i, yi - 1];
            }
            for (int i = 0; i < y; i++)
            {
                ys += massiv[xi - 1, i];
            }
            Console.WriteLine("Sum of " + yi + " row = " + xs);
            Console.WriteLine("Sum of " + xi + " column= " + ys);
        }
    }
}

