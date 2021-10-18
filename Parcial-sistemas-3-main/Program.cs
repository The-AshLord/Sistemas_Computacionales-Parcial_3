using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Parcial_scripting_3_Main
{
    class Program
    {
        static void Main(string[] args)
        {
                Cat hopkins = new Cat("Hopkins", 1);
                Dog alfred = new Dog("Alfred");
                Canary Tweety = new Canary("Tweety");
            
                alfred.Smell(alfred, hopkins);
                hopkins.Speak(hopkins);
                Tweety.See(Tweety, hopkins);
        }
    }
}
