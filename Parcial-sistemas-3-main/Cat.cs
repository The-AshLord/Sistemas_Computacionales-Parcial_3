using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Parcial_scripting_3_Main
{
    public class Cat : Subject
    {
        public Observer observer;
        public Subject subject;

        public Cat(string name, int type) : base(name, type) { }
       
        
        public void Speak(Cat cat)
        {
            Console.WriteLine("Nea me llamo " + cat.name);
            NotifyObservers(cat);
        }
    }
}
