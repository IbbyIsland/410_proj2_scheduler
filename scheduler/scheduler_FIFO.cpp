/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <numeric>
#include <algorithm>
#include "../includes/scheduler_FIFO.h"


using namespace std;




	//override base class behaviour if necessary, otherwise call it
	//should refer back to scheduler.cpp?
	bool  Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
		//use the given tick count for this process to see if it should switch processes depending on how much time it has
		//just make sure the process isn't finished
		//similar to scheduler.cpp
		if (p.remaining_cpu_time <= 0){
			return true;
		}
		else{
			return false;
		}
	}

	//FIFO - not preemptive - no sorting needed
	void Scheduler_FIFO::sort(){

	}




