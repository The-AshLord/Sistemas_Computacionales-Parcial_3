using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Parcial_scripting_3_Main
{
    public abstract class Subject
    {
        public static int maximunObservers = 20;
        public Observer[] observerList = new Observer[maximunObservers];
        public string name;
        public int type;

        public Subject(string name, int type)
        {
            this.name = name;
            this.type = type;
        }

        public virtual int RegisterObserver(Subject subject, Observer observer)
        {

            for (int i = 0; i < maximunObservers; i++)
            {
                if (subject.observerList[i] == null)
                {
                    subject.observerList[i] = observer;
                    return 0;
                }

            }
            return RegisterObserver(subject, observer); ;
        }
        
        public void NotifyObservers(Subject subject)
        {
            for (int i = 0; i < maximunObservers; i++)
            {
                if (subject.observerList[i] != null)
                {
                    subject.observerList[i].Notify(subject.observerList[i], subject);
                }
            }
        }
    }
}

