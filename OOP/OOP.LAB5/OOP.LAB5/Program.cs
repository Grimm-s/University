using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB5
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
        public int Weight { get; set;}
        public Animal()
        {
            Name = null;
            Breed = null;
            BreedCharacteristic = null;
            Weight = 0;
        }
        public Animal(string Name,string Breed,string BreedCharacteristic)
        {
            this.Name = Name;
            this.Breed = Breed;
            this.BreedCharacteristic = BreedCharacteristic;
        }

        public static bool operator >(Animal a1, Animal a2)
        {
            return a1.Weight > a2.Weight;
        }
        public static bool operator <(Animal a1, Animal a2)
        {
            return a1.Weight < a2.Weight;
        }

        public virtual void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic}");
        }
    }
    class Cat : Animal
    {
        public string Color { get; set; }

        public Cat():base()
        {
            Color = null;
        }
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
        public Dog():base()
        {
            Age = 0;
        }
        public Dog(string Name, string Breed, string BreedCharacteristic,int Age):base(Name, Breed, BreedCharacteristic)
        {
            this.Age = Age;
        }
        public override void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic} Age:{Age}");
        }
    }

    class Parrot : Animal
    {
        public bool Talkative { get; set; }
        public Parrot():base()
        {
            Talkative = false;
        }
        public Parrot(string Name, string Breed, string BreedCharacteristic,bool Talkative):base(Name, Breed, BreedCharacteristic)
        {
            this.Talkative = Talkative;
        }
        public override void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic} Talkative:{Talkative}");
        }
    }

    class Cats
    { 
        Cat[] cats;

        public Cats()
        {
            cats = new Cat[5];
        }
       
        public Cat this[int index]
        {
            get
            {
                return cats[index];
            }
            set
            {
                cats[index] = value;
            }
        }
    }
}