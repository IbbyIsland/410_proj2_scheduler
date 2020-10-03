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

bool shortestTimeRemainingSort(PCB a, PCB b);
	//override base class behaviour if necessary, otherwise call it
	bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
		//sort the function first by shortest time first



		if (ready_q->front().remaining_cpu_time < p.remaining_cpu_time){
			return true;
		}
		//test if the remaining time is less than 0
		if (ready_q->front().remaining_cpu_time <= 0){
			return true;
		}
		else{
			return false;
		}

	}

	//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
	void Scheduler_SRTF::sort(){
		//make a vector to hold the sorted vector?
		int i = 0;
		vector<PCB> newVector;

		for (int i; i < ready_q->size(); i++){
			newVector.push_back(ready_q->front());
			ready_q->pop();

		}
		//try to sort the new vector, and then add it into the ready_q, element after element
		//check back to this, check algorithm needed to sort the vector by making a new function?
		//look at geeks for geeks implementation to specify the sort
		std::sort(newVector.begin(), newVector.end(), shortestTimeRemainingSort);
		for (int i = 0; i < newVector.size(); i++){
			ready_q->push(newVector.at(i));
		}
	}
	// algorithm to compare between two processes
	bool shortestTimeRemainingSort(PCB a, PCB b){
		return (a.remaining_cpu_time > b.remaining_cpu_time);
	}



