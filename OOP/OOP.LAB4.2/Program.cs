using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB4._2
{
    class Program
    {
        static void Main(string[] args)
        {

        }
    }
    interface IAnimal
    {
        string Name { get; set; }
        string Breed { get; set; }
        string BreedCharacteristic { get; set; }
        void Display();
       // void Friendship(object emp);
    }

    class Animal : IAnimal
    {
        public string Name { get; set; }
        public string Breed { get; set; }
        public string BreedCharacteristic { get; set; }
        public Animal()
        {
            Name = null;
            Breed = null;
            BreedCharacteristic = null;
        }
        public Animal(string Name, string Breed, string BreedCharacteristic)
        {
            this.Name = Name;
            this.Breed = Breed;
            this.BreedCharacteristic = BreedCharacteristic;
        }
        public void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic}");
        }
        public void Friendship(Animal emp)
        {
            Console.WriteLine(Name + " is friends with " + emp.Name);
        }

    }
    class Cat : Animal
    {
        public string Color { get; set; }
        public Cat(string Name, string Breed, string BreedCharacteristic, string Color) : base(Name, Breed, BreedCharacteristic)
        {
            this.Color = Color;
        }

        public new void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic} Color:{Color}");
        }
        public new  void Friendship(Dog emp)
        {
            Console.WriteLine(Name + " is friends with " + emp.Name);
        }

    }
    class Dog : Animal
    {
        public int Age { get; set; }
        public Dog(string Name, string Breed, string BreedCharacteristic, int Age) : base(Name, Breed, BreedCharacteristic)
        {
            this.Age = Age;
        }
        public new void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic} Age:{Age}");
        }
        public new void Friendship(Cat emp)
        {
            Console.WriteLine(Name + " is friends with " + emp.Name);
        }
    }
}
