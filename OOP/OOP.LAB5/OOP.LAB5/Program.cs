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
            Cats cats = new Cats();
            cats[0] =new Cat("Майк", "Кот", "Angry", 5,14);
            cats[1] =new Cat("Майк", "Кот", "Sad", 7,20);
            cats[2] =new Cat("Джеки", "Собака", "Clever", 10,12);
            cats[3] =new Cat("Билл", "Кот", "Shy", 4,15);
            cats[4] =new Cat("Ванесса", "Собака", "Stupid", 15,8);
            for (int i = 0; i < 5; i++)
            {
                cats[i].Display();
            }

            bool res = cats[0] > cats[1];
            Console.WriteLine(res);
            cats[2]++;
            cats[2].Display();
            
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
        public Animal(string Name,string Breed,string BreedCharacteristic,int weight)
        {
            this.Name = Name;
            this.Breed = Breed;
            this.BreedCharacteristic = BreedCharacteristic;
            this.Weight = Weight;
        }

    

        public virtual void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic}");
        }
    }
    class Cat : Animal
    {
        public int Age { get; set; }

        public Cat():base()
        {
            Age = 0;
        }
        public Cat(string Name, string Breed, string BreedCharacteristic,int Age,int Weight) :base(Name,Breed,BreedCharacteristic,Weight)
        {
            this.Age = Age;
        }

        public override void Display()
        {
            Console.WriteLine($"Name:{Name} Breed:{Breed} BreedCharacteristic:{BreedCharacteristic} Age:{Age}");
        }
        public static bool operator >(Cat a1, Cat a2)
        {
            return a1.Weight > a2.Weight;
        }
        public static bool operator <(Cat a1, Cat a2)
        {
            return a1.Weight < a2.Weight;
        }

        public static Cat operator ++(Cat a)
        {
            a.Age++;
            return a;
        }
        

    }
    class Dog : Animal
    {
        public int Age { get; set; }
        public Dog():base()
        {
            Age = 0;
        }
        public Dog(string Name, string Breed, string BreedCharacteristic,int Age,int Weight):base(Name, Breed, BreedCharacteristic,Weight)
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
        public Parrot(string Name, string Breed, string BreedCharacteristic,bool Talkative,int Weight):base(Name, Breed, BreedCharacteristic,Weight)
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