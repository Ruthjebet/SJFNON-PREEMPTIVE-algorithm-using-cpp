#ifdef _WIN32
    #define command "cls"
#else
    #define command "clear"
#endif


#include <iostream>
#include"TaskManager.h"
#include "task.h"
#include <stdlib.h>

using namespace std;

TaskManager* manager=new TaskManager();
static int mytime=0;

int main();

int menu(int choices){
    



    switch (choices)
        {
        case 1:
        {
            double me=0.0;
            string nm,ds;
            cin.ignore();
            cout<<"\nEnter Task Name\n";
            getline(cin,nm);
            cout<<"\nEnter Burst Time\n";
            cin>>me;
            cin.ignore();
            cout<<"\nEnter Task Description\n";
            getline(cin,ds);
            cout<<"\n Enter arrival Time \n";
            double arrival;
            cin>>arrival;
            task tmp(nm,me,ds);
            tmp.arrive(arrival);
            manager->addProcess(tmp);
            break;
        }
        case 2:
        {
            system(command);
            cout << "\n\n";
            manager->showAllProcesses();
            cout<<"\n\nEnter the number of the task to delete\t:\t";
            int num;
            cin>>num;
            if(num>manager->size()){
                cout<<"\nHio haiko msee\n Ebu try.Tena\n";
                main();
            }
            else
            {
                manager->deleteProcess(num-1);
                cout<<"\nUshadelete Venye Ulikuw.Unataka\n";

            }
            break;
        }
        case 3:
        {
            system(command);
            cout << "\t\t All Tasks in queue\n";
            manager->showProcesses();

           
            break;
        }
        case 4:
        {
            cout<<"start of simulation";
            manager->sjf();
            cout<<"End Of simulation";
            
            system(0);
            break;
        }
        case 5:
            cout << "Exit";
            system(0);
        }
        main();
    return choices;
}


int main()
{   
    int choices;
    cout<< "Welcome"<<endl;
    cout<< "Choice:\n1.Add task\n 2.Delete task \n 3.See All tasks \n 4.Simulate SJF \n 5.Exit"<<endl;
    cout<<" Enter choice:";
    cin>>choices;
    if(choices!=5)
        choices = menu(choices);
    else
        cout<<"\n\nexiting.\t Dont forget to Subscribe to my youtube channel\n";

  return 0;  
}

