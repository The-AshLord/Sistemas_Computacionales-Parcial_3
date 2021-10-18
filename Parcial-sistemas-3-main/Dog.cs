using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Parcial_scripting_3_Main
{
    public class Dog : Observer
    {
        public Cat cat;
        public Dog(string name) : base(name) { }

        public void Smell(Dog dog, Cat cat)
        {
            cat.RegisterObserver(cat, this);
            Console.WriteLine(dog.name + " me hueli al " + cat.name);
        }
    }
}
