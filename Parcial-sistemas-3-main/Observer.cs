using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Parcial_scripting_3_Main
{
    public abstract class Observer
    {
        public string name;
        public Observer(string name)
        {
            this.name = name;
        }

        public void Notify(Observer observer, Subject subject)
        {
            Console.WriteLine(observer.name + " escucho a " + subject.name);
        }

    }
}

