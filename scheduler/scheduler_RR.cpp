/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <numeric>
#include <algorithm>
#include "../includes/scheduler_RR.h"

using namespace std;

// dont sort since it's preemptive




	//override base class behaviour if necessary, otherwise call it
	//figure out the conditional statement to see if it should switch statments
	 bool  Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p){

		if ((p.required_cpu_time - p.remaining_cpu_time) % time_slice <= 0 || p.remaining_cpu_time == 0){
			return true;
		}
		return false;
	}

	//RR - preemptive - no sorting of ready_q needed.
	 void Scheduler_RR::sort(){
		 preemptive = true;//had to put a comment to attempt to define it so it doesn't give an error
	 }
