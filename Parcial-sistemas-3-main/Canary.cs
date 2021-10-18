using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Parcial_scripting_3_Main
{
    public class Canary : Observer
    {
        public Canary(string name) : base(name) { }
        

        public void See(Canary canary, Cat cat)
        {
            cat.RegisterObserver(cat, this);
            Console.WriteLine(canary.name + " esta viendo al " + cat.name);
        }

    }
}
