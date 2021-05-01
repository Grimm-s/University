﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP.LAB4._3
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
        void Friendship();
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
        public Animal(string Name, string Breed, string BreedCharacteristic)
        {
            this.Name = Name;
            this.Breed = Breed;
            this.BreedCharacteristic = BreedCharacteristic;
        }
        public virtual void Display()
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

        public override void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic} Color:{Color}");
        }
        public void Friendship(Dog emp)
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
        public override void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic} Age:{Age}");
        }
        public void Friendship(Cat emp)
        {
            Console.WriteLine(Name + " is friends with " + emp.Name);
        }
    }
}
