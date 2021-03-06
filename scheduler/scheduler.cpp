/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../includes/scheduler.h"
#include "../includes/constants.h"
#include <queue>
#include <numeric>
#include <algorithm>

	//add a process, either a new one or one that
	//had been running on the CPU and has been preempted
	void Scheduler::add(PCB p){
		//use push? or push_back? look at difference
		ready_q->push(p);
		sort();

	}

	//get next process
	//get next process on the vector
	PCB Scheduler::getNext(){
		//relate this to getNext in previous project
		if (isEmpty()){
			return PCB();
		}
		PCB myNext;
		myNext = ready_q->front();
		ready_q->pop();
		return myNext;


	}

	//returns true if there are no  jobs in the readyQ
	//false otherwise
	bool Scheduler::isEmpty(){
		//check if its empty or not
		if (ready_q->empty() == true){
			return true;
		}
		else{
			return false;
		}

	}

	//if process has completed (used all its remaining_cpu_time) or
	//if we are using a preemptive scheduling algorithm and the
	//timeslice is over then its time to switch processes
	//returns:
	//true - switch processes
	//false - do not switch
	bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
		//if its remaining time is done, return true
		if (p.remaining_cpu_time <= 0 || preemptive && tick_count - p.start_time >= time_slice){
			return true;
		}
		return false;
	}

	// sort  ready_q based on the scheduler algorithm used whenever add(PCB p) is called








