#include "TaskManager.h"
#include <unistd.h>


using namespace std;
static int mytime=0;

void TaskManager::hsort(task* arr,int len)
{
	int n=len;
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}

}


void TaskManager::heapify(task* arr,int len,int root)
{
	int n=len;
	int i=root;
	int smaller = root; // Initialize smaller as root
	int l = 2 * root + 1; // left = 2*i + 1
	int r = 2 * root + 2; // right = 2*i + 2

	if (l < n && arr[l] > arr[smaller])
		smaller = l;


	if (r < n && arr[r] > arr[smaller])
		smaller = r;


	if (smaller != i) {
		swap(arr[i], arr[smaller]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, smaller);
	}
}

//simulation
void TaskManager::sjf()
{
	bool processed=false;
	task* current=NULL;
	while(!processed)
	{
		
		if(current==NULL)
		{
			cout<<"\n At Time "<<mytime<<" ";
			int num=countReady(mytime);
			cout<<" \n "<<countReady(mytime)<<" Tasks are Ready ";
			if(num>0)
			{

				task* readyTasks=getReadyProcesses(mytime);
				//displayTasks(readyTasks,num);
				hsort(readyTasks,num);
				cout<<"\n\n\tThe Ready tasks in order of their burst time\n";
				displayTasks(readyTasks,num);
				cout<<"\n\n \t\t Processing the task with the smallest burst time";
				current=&readyTasks[0];
				cout<<" \nStart of processing Task \n\t "+current->toString()<<"\n\n";

			}
			else
			{
				cout<<" CPU in Idle State ";
			}

		}
		
		
		if(current!=NULL){
			cout<<" - - ";

			current->run(1);
			if(current->completed()){
			cout<<"\nTask Completed At Time "<<mytime+1<<" \n\n";
			completed++;
			updateStatus(*current);
			current=NULL;
			processed=true;
		}
		
		}

		


		usleep(10000);
		mytime++;
	}
}