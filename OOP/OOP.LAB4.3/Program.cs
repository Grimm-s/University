using System;
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
            var cat1 = new Cat("Jack","1","Angry","Black");
            var cat2 = new Cat();
            var dog1 = new Dog("Billy", "3", "Quiet", 10);
            var dog2 = new Dog();
            cat1.Display();
            cat2.Display();
            dog1.Display();
            dog2.Display();
            cat1.Friendship(dog1);
            Animal cat3 = new Cat("Milly", "1", "Angry", "Black");
            cat3.Display();
            cat3.Friendship(cat1);
            dog1.Friendship(cat1);
        }
    }
    

    abstract class Animal
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
        public Cat() : base() { }
        public  new void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic} Color:{Color}");
        }
    }
    class Dog : Animal
    {
        public int Age { get; set; }
        public Dog(string Name, string Breed, string BreedCharacteristic, int Age) : base(Name, Breed, BreedCharacteristic)
        {
            this.Age = Age;
        }
        public Dog() : base() { }
        public  new void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic} Age:{Age}");
        }
    }
}
