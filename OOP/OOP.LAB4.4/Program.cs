using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB4._4
{

    class Program
    {
        static void Main(string[] args)
        {
            var a1 = new Animal("Майк","Кот",20, 100);
            var a2 = new Animal("Джеки", "Собака", 30, 120);
            var a3 = new Animal("Билл", "Кот", 15, 90);
            var a4 = new Animal("Ванесса", "Собака", 35, 130);
            var a5 = new Animal("Боб", "Кот", 18, 115);
            Animal[] animals = new Animal[5]{a1,a2,a3,a4,a5};
            var zoo = new Zoo(a1,a2,a3,a4,a5);
            Array.Sort(animals,new HeightAndWeightComparer());
            foreach (Animal animal in animals )
            { 
                animal.Display();

            }

            Console.WriteLine();
            foreach (Animal dogsAndCats in zoo)
            {
                dogsAndCats.Display();

            }
            
            
        }
    }


    class Animal : IComparable
    {
        public string Name { get; set; }
        public string Breed { get; set; }
        public int Weight { get; set; }
        public int Height { get; set; }

        public Animal()
        {
            Name = null;
            Breed = null;
            Weight = 0;
            Height = 0;
        }
        public Animal(string Name, string Breed,int Weight,int Height)
        {
            this.Name = Name;
            this.Breed = Breed;
            this.Weight = Weight;
            this.Height = Height;
        }
        public void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} Weight{Weight}, Height{Height} ");
        }
        public int CompareTo(object o)
        {
            Animal p = o as Animal;
            if (p != null)
                return this.Height.CompareTo(p.Height);
            else
                throw new Exception("Невозможно сравнить два объекта");
        }
       
    }
    class HeightAndWeightComparer : IComparer<Animal>
    {
        public int Compare(Animal x, Animal y)
        {
            if (x.Height > y.Height && x.Weight > y.Weight) return 1;
            if (y.Height > x.Height && y.Weight > x.Weight) return -1;
            else return -0;
        }
    }
    class Zoo :IEnumerable
    {
        
        List<Animal> dogsAndCats = new List<Animal>();

        public Zoo(Animal a1, Animal a2,Animal a3,Animal a4, Animal a5)
        {
            dogsAndCats.Add(a1);
            dogsAndCats.Add(a2);
            dogsAndCats.Add(a3);
            dogsAndCats.Add(a4);
            dogsAndCats.Add(a5);
        }

        public IEnumerator GetEnumerator()
        {
            return dogsAndCats.GetEnumerator();
        }
    }
    
}
