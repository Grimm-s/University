using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB4
{
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
    class Animal
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
        public Animal(string Name,string Breed,string BreedCharacteristic)
        {
            this.Name = Name;
            this.Breed = Breed;
            this.BreedCharacteristic = BreedCharacteristic;
        }
        public virtual void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic}");
        }
    }
    class Cat : Animal
    {
        public string Color { get; set; }
        public Cat(string Name, string Breed, string BreedCharacteristic,string Color) :base(Name,Breed,BreedCharacteristic)
        {
            this.Color = Color;
        }

        public override void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic} Color:{Color}");
        }

    }
    class Dog : Animal
    {
        public int Age { get; set; }
        public Dog(string Name, string Breed, string BreedCharacteristic,int Age):base(Name, Breed, BreedCharacteristic)
        {
            this.Age = Age;
        }
        public override void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic} Age:{Age}");
        }
    }
}
