using System;
using System.Collections.Generic;

namespace DelegateTest
{
    class Calculator
    {
        private Dictionary<string, Func<double, double, double>> operations =
            new Dictionary<string, Func<double, double, double>>
            {
                { "+", (x, y) => x + y },
                { "-", (x, y) => x - y },
                { "*", (x,y) => x * y },
                { "/", (x,y) => x / y },
            };
        
        public void AddOperation(string op, Func<double, double, double> body)
        {
            operations.Add(op, body);
        }
        public double DoOperation(string op, double x, double y)
        {
            return operations[op](x, y);
        }
    }
    class Program
    {
       
        static void Main(string[] args)
        { 
            var calc = new Calculator();
            calc.AddOperation("%", (x, y) => x % y);
            var mod = calc.DoOperation("%", 3.0, 2.0);
            Console.WriteLine(mod);

        }
    }
}