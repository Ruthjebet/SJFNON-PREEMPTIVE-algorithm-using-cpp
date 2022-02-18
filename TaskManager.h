#ifndef TaskManager_h
#define TaskManager_h


#include <iostream>
#include <string>
#include "task.h"

using namespace std;


class TaskManager
{
private:
	task * processes;
	int s;
	int completed=0;


public:
	TaskManager()
	{
		processes=NULL;
		s=0;
	}

	~TaskManager()
	{
		delete[] processes;
		processes=NULL;
		s=0;
	}

	TaskManager(TaskManager& other)
	{
		s=other.size();
		processes=new task[s];
		for(int i=0;i<s;i++)
			processes[i]=other[i];
	}

	task& operator [] (int i)
	{
		return processes[i];
	}

	

	int size(){return s;}


	void addProcess(task t)
	{	
		task* tmp=new task[s+1];
		for(int i=0;i<s;i++)
			tmp[i]=processes[i];
		tmp[s]=t;
		s++;

		if(processes!=NULL)
			delete[] processes;
		processes=tmp;
		cout<<"\n\nTask Added Successsfully\n\n";
	}
//function that shows all processes
	void showAllProcesses()
	{
		cout<<"\n\n"<<size()<<" \n All Processes "<<"\n";
		displayTasks(processes,size());
		cout<<"\nEnd\n";
	}

	void showProcesses()
	{
		cout<<"\n\n"<<size()<<" \n  Processes  in Queue"<<"\n";
		int num=1;
		for(int i=0;i<size();i++)
			if(!processes[i].completed()){
				cout<<num<<". "<<processes[i]<<endl;
				num++;
			}
		cout<<"\nEnd\n";
	}

	void deleteProcess(int index)
	{
		if(index<size())
		{
			task* tmp=new task[s-1];
			int j=0;
			for(int i=0;i<s;i++)
				if(index!=i){
					tmp[j]=processes[i];
					j++;
				}
				else
					continue;
			s--;

			delete[] processes;
			processes=tmp;
		}

	}

	void updateStatus(task t)
	{
		for(int i=0;i<size();i++)
			if(processes[i].getName()==t.getName())
				processes[i]=t;

	}



	void hsort(task* arr,int len);
	void heapify(task* arr,int len,int root);
	void sjf();


	void displayTasks(task* tasks,int size)
	{
		for(int i=0;i<size;i++)
			cout<<"\n"<<i+1<<". "<<tasks[i];
	}

	task* getReadyProcesses(int time)
	{
		task* tasks=NULL;
		int num=countReady(time);
		if(num>0)
		{
			int index=0;
			tasks=new task[num];
			for(int i=0;i<size();i++)
				if(processes[i].ready(time))
				{
					tasks[index]=processes[i];
					index++;
				}
		}

		return tasks;
	}

	int countReady(int time)
	{
		int num=0;
		for(int i=0;i<size();i++)
			if(processes[i].ready(time))
				num++;
		return num;
	}
	

	
};




#endif