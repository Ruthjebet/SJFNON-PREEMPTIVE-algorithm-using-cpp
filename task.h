#ifndef task_h
#define task_h

#include<stdbool.h>
#include<iostream>
#include<string.h>

class task{
private:
	double remaining_time,burst_time,arrival_time,end_time;
	std::string task_name,description;
public:

	std::string getName()
	{
		return task_name;
	}
	

	task()
	{
		static int counter=0;
		burst_time=rand()%100;
		remaining_time=burst_time;
		arrival_time=rand()%100;
		end_time=0.0;
		task_name="Task "+std::to_string(counter);
		description="Task "+std::to_string(counter)+" Description";
		counter++;
	}

	

	 task(double burst_time)
	 {
	 	static int counter=0;
	 	remaining_time=arrival_time=end_time=0.0;
	 	this->burst_time=burst_time;
	 	remaining_time=burst_time;
	 	task_name="Task "+std::to_string(counter);
		description="Task "+std::to_string(counter)+" Description";
		counter++;
	 }

	 task(std::string task_name,double burst_time,std::string description)
	 {
	 	arrival_time=end_time=0.0;
	 	this->task_name=task_name;
	 	this->description=description;
	 	this->burst_time=burst_time;
	 	remaining_time=burst_time;
	 }


	 void arrive(double arrival_time){
	 	this->arrival_time=arrival_time;
	 }

	 void end(double end_time)
	 {
	 	this->end_time=end_time;
	 }

	 void run(int time)
	 {
	 	remaining_time-=time;
	 }

	 double & remaining()
	 {
	 	return this->remaining_time;
	 }

	 bool ready(int time)
	 {
	 	return (arrival_time<=time&&!completed());
	 }

	 bool completed()
	 {
	 	return (remaining()==0);
	 }

	 std::string toString()
	 {
	 	std::string tmp="Task : "+task_name+"\tBurst Time : "+std::to_string(burst_time)+"\tArrival time : "+std::to_string(arrival_time)+(completed()?("\tCompleted At : "+std::to_string(end_time)):("\tRemaining Time : "+std::to_string(remaining())))+"\tDescription : "+description;
	 	return tmp;
	 }
 
	 friend std::ostream& operator << (std::ostream& out,task& t)
	 {
	 	out<<t.toString();
	 	return out;
	 }

	 friend bool operator == (task& me,task& other)
	 {
	 	return (me.burst_time==other.burst_time);
	 }

	 friend bool operator > (task& me,task& other)
	 {
	 	return (me.burst_time>other.burst_time);
	 }

	 friend bool operator >= (task& me,task& other)
	 {
	 	return (me.burst_time>=other.burst_time);
	 }

	 friend bool operator <= (task& me,task& other)
	 {
	 	return (me.burst_time<=other.burst_time);
	 }


	 friend bool operator <(task& me,task& other)
	 {
	 	return (!(me>other));
	 }

	 task& operator=(task const& other)
	 {
	 	task_name=other.task_name;
	 	description=other.description;
	 	burst_time=other.burst_time;
	 	arrival_time=other.arrival_time;
	 	end_time=other.end_time;
	 	remaining_time=other.remaining_time;
	 	return *this;
	 }



};


#endif