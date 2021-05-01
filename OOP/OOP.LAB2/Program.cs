using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB2
{

    class Functions
    {
        public static void Sorting(int[] arr, int first, int last)
        {
            int p = arr[(last - first) / 2 + first];
            int temp;
            int i = first, j = last;
            while (i <= j)
            {
                while (arr[i] < p && i <= last) ++i;
                while (arr[j] > p && j >= first) --j;
                if (i <= j)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    ++i; --j;
                }
            }
            if (j > first) Sorting(arr, first, j);
            if (i < last) Sorting(arr, i, last);
        }
        static double f(double x)

        {          
            double y = 6 * Math.Pow(x, 4) - 3 * Math.Pow(x, 3) + 8 * Math.Pow(x, 2) - 25;
            return y;
        }
        public static double bicect(double left, double right)

        {           
            double center = 0;
            double eps = 0.00001;
            while (right - left > eps * 2)
            {

                center = (right - left) / 2 + left;

                if (f(center) * f(left) > 0)

                    left = center;

                else

                    right = center;

            }

            return center;

        }       
    }

    class Tasks
    {
        public static void Task1()
        {
            Random aRand = new Random();
            Console.Write("Select massiv size:");
            int Size;
            Size = Convert.ToInt32(Console.ReadLine());
            int[] massiv = new int[Size];
            for (int i = 0; i < Size; i++)
            {
                massiv[i] = aRand.Next(100);
                Console.Write(massiv[i] + " ");
            }
            Console.WriteLine();
            Functions.Sorting(massiv, 0, Size - 1);
            for (int i = 0; i < Size; i++)
            {

                Console.Write(massiv[i] + " ");
            }
        }
        public static void Task2()
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
        public static void Task3()
        {
            Random aRand = new Random();
            Console.Write("Select massiv size:");
            int Size, q = 0;
            Size = Convert.ToInt32(Console.ReadLine());
            List<int> numbers_e = new List<int>();
            List<int> numbers_i = new List<int>();
            int[] massiv = new int[Size];           
            for (int i = 0; i < Size; i++)
            {
                massiv[i] = aRand.Next(100);
                Console.Write(massiv[i] + " ");
            }
            Console.WriteLine();

            for (int i1 = 0; i1 < Size; i1++)
            {
                if (!numbers_e.Contains(massiv[i1]))
                {
                    int n = 0;
                    numbers_e.Add(massiv[i1]);
                   
                    for (int i2 = 0; i2 < Size; i2++)
                    {
                        if (massiv[i1] == massiv[i2])
                        {
                            n++;
                        }
                    }
                    numbers_i.Add(n);
                   
                    q++;
                }
                else
                {
                    continue;
                }
            }
            
            
            for (int i = 0; i < numbers_e.Count; i++)
            {
                
                Console.WriteLine($"Element {numbers_e[i]} is repeated {numbers_i[i]} times");
            }

        }
        public static void Task4()
        {
            Random aRand = new Random();
            int max, min, imax = 0, imin = 0;
            Console.Write("Select massiv size:");
            int Size;
            Size = Convert.ToInt32(Console.ReadLine());
            int[] massiv = new int[Size];
            for (int i = 0; i < Size; i++)
            {
                massiv[i] = aRand.Next(100);
                Console.Write(massiv[i] + " ");
            }
            Console.WriteLine();
            min = massiv[0];
            max = massiv[0];
            for (int i = 0; i < Size; i++)
            {
                if (massiv[i] < min)
                {
                    imin = i;
                    min = massiv[i];
                }
                if (massiv[i] > max)
                {
                    imax = i;
                    max = massiv[i];
                }
            }
            Console.WriteLine("Max element = " + max + ",index = " + imax);
            Console.WriteLine("Min element = " + min + ", index = " + imin);
        }
        public static void Task5()
        {
            Random aRand = new Random();
            int SearchElement, SearchIndex;
            Console.Write("Select massiv size:");
            int Size;
            Size = Convert.ToInt32(Console.ReadLine());
            int[] massiv = new int[Size];
            for (int i = 0; i < Size; i++)
            {
                massiv[i] = aRand.Next(100);
                
            }
            Functions.Sorting(massiv, 0, Size - 1);
            for (int i = 0; i < Size; i++)
            {
               
                Console.Write(massiv[i] + " ");
            }
            Console.WriteLine();
            Console.WriteLine("Select element for searching:");
            SearchElement = Convert.ToInt32(Console.ReadLine());

            SearchIndex = Array.BinarySearch(massiv, SearchElement);
            if (SearchIndex >= 0)
            {
                Console.WriteLine("Element index = " + SearchIndex);
            }
            else
            {
                Console.WriteLine("Element not found");
            }
            

        }
        public static void Task6()
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
        public static void Task7()
        {
            Random aRand = new Random();
            int x, y, max = 0, min = 0, imax, imin;
            Console.Write("Select x:");
            x = Convert.ToInt32(Console.ReadLine());
            Console.Write("Select y:");
            y = Convert.ToInt32(Console.ReadLine());
            int[,] massiv = new int[x, y];
            int[] maxindex = new int[2];
            int[] minindex = new int[2];
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
            min = massiv[0, 0];
            max = massiv[0, 0];
            for (int i2 = 0; i2 < y; i2++)
            {
                for (int i1 = 0; i1 < x; i1++)
                {

                    //max = Math.Max(massiv[i1, i2], max);
                    if (Math.Max(massiv[i1, i2], max) == massiv[i1, i2])
                    {
                        max = Math.Max(massiv[i1, i2], max);
                        maxindex[0] = i1;
                        maxindex[1] = i2;
                    }
                    if (Math.Min(massiv[i1, i2], min) == massiv[i1, i2])
                    {
                        min = Math.Min(massiv[i1, i2], min);
                        minindex[0] = i1;
                        minindex[1] = i2;
                    }

                }
                
            }
            Console.WriteLine($"Max element = {max}, index ={maxindex[0]},{maxindex[1]}");
            Console.WriteLine($"Min element = {min}, index ={minindex[0]},{minindex[1]}");

        }
        public static void Task8()
        {
            double right, left;
            Console.WriteLine("Selecet right:");
            right = Convert.ToDouble(Console.ReadLine());
            
            Console.WriteLine("Selecet left:");
            left = Convert.ToDouble(Console.ReadLine());
            
            double x1 = Functions.bicect(0, right);

            double x2 = Functions.bicect(left, 0);
            Console.WriteLine("6x^4-3x^3+8x^2-25=0");

            Console.WriteLine("Bisection method:");

            Console.WriteLine("x1={0},x2= {1}", x1, x2);

            Console.ReadKey();
        }
        public static void Task9()
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
    }
    class Program
    {

        static void Main(string[] args)
        {
           // Console.BackgroundColor = ConsoleColor.White;
            Console.ForegroundColor = ConsoleColor.DarkGreen;
            int Choice;
            while (true)
            {
                Console.WriteLine("Rybak Semen IPZ-11");
                Console.WriteLine("----------Menu----------");
                Console.Write("Select the task number:");
                Choice = Convert.ToInt32(Console.ReadLine());
                switch (Choice)
                {
                    case 1:
                        Tasks.Task1();
                        Console.ReadKey();
                        break;
                    case 2:
                        Tasks.Task2();
                        Console.ReadKey();
                        break;
                    case 3:
                        Tasks.Task3();
                        Console.ReadKey();
                        break;
                    case 4:
                        Tasks.Task4();
                        Console.ReadKey();
                        break;
                    case 5:
                        Tasks.Task5();
                        Console.ReadKey();
                        break;
                    case 6:
                        Tasks.Task6();
                        Console.ReadKey();
                        break;
                    case 7:
                        Tasks.Task7();
                        Console.ReadKey();
                        break;
                    case 8:
                        Tasks.Task8();
                        Console.ReadKey();
                        break;
                    case 9:
                        Tasks.Task9();
                        Console.ReadKey();
                        break;
                    default:
                        Console.WriteLine("Incorrect input!");
                        Console.ReadKey();
                        System.Environment.Exit(0);
                        break;
                }
                Console.Clear();
            }
        }
    }
}
