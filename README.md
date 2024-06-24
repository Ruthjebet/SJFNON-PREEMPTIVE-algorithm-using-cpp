#SJF Non-Preemptive CPU Scheduling Algorithm in C++
#Overview
This project demonstrates the Shortest Job First (SJF) Non-Preemptive CPU Scheduling algorithm using a priority queue in C++. The SJF algorithm selects the process with the shortest burst time to execute next. In the non-preemptive version, once a process starts its execution, it runs to completion before the next process is selected.

#Features
Add tasks with their burst times and arrival times.
Display all tasks.
Delete a specific task.
Simulate SJF Non-Preemptive scheduling.
User-friendly menu-driven interface.

#Requirements
C++ compiler (e.g., g++, clang++)
Standard Template Library (STL) support

#Files
main.cpp: Contains the main logic and menu for the SJF Non-Preemptive scheduling algorithm.
TaskManager.h: Header file for the TaskManager class.
task.h: Header file for the task class.

#How it Works
Input Handling:

The user is presented with a menu to interact with the task manager.
Tasks can be added with burst time and arrival time.
Tasks can be deleted by specifying the task number.
Process Scheduling:

The sjf method in TaskManager implements the SJF Non-Preemptive scheduling.
The simulation displays the order of task execution and computes waiting and turnaround times.
Output:

The waiting time and turnaround time for each task are displayed during simulation.
Users can view all tasks or delete specific tasks.
