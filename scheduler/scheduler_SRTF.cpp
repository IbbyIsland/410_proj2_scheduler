/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <numeric>
#include <algorithm>
#include "../includes/scheduler_SRTF.h"

using namespace std;

//figure out how the remaining time for the process can be less than 0?

bool shortestTimeRemainingSort(PCB y, PCB z);
	//override base class behaviour if necessary, otherwise call it
	bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
		//sort the function first by shortest time first



//		if (p.remaining_cpu_time <= 0){
//			return true;
//		}
//		//test if the remaining time is less than 0
//		if (ready_q->front().remaining_cpu_time < p.remaining_cpu_time && (ready_q->empty() == false) ){
//			return true;
//		}
//		else{
//			return false;)
//		}
		//just use the sort function
		sort();

		return Scheduler::time_to_switch_processes(tick_count, p);
	}

	//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
	void Scheduler_SRTF::sort(){
		//make a vector to hold the sorted vector?
		preemptive = true;
		//int i = 0;
		vector<PCB> newVector;
		while (ready_q->empty() == false){
			newVector.push_back(ready_q->front());
			ready_q->pop();
		}
		//makes the infinite loop?
//		for (i; i < ready_q->size(); i++){
//			newVector.push_back(ready_q->front());
//			ready_q->pop();
//
//
//		}
		//try to sort the new vector, and then add it into the ready_q, element after element
		//check back to this, check algorithm needed to sort the vector by making a new function?
		//look at geeks for geeks implementation to specify the sort
		std::sort(newVector.begin(), newVector.end(), shortestTimeRemainingSort);

		for (PCB process: newVector){

			ready_q->push(process);
		}
	}
	// algorithm to compare between two processes
	bool shortestTimeRemainingSort(PCB y, PCB z){
		if (y.remaining_cpu_time < z.remaining_cpu_time){
			return true;
		}
		else{
			return false;
		}
	}



