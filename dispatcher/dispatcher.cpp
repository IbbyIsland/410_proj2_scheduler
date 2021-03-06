/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <numeric>
#include <algorithm>
#include "../includes/dispatcher.h"

using namespace std;

	//pull current process (if any) off CPU and return it
	//if nothing on CPU returns an uninitialized PCB
	PCB Dispatcher::get_from_CPU(){
		//use the is_valid_job from the header file
		is_valid_job_on_cpu = false;
		//is_valid_job_on_cpu = true;

		PCB variable = cpu->get_process_off_core();
		if (variable.process_number == UNINITIALIZED){
			is_valid_job_on_cpu = true;
		}

		return variable;
	}

	//place the current process on the CPU for execution
	//look at CPU.h for its methods
	void Dispatcher::put_on_CPU(PCB  &process){

		//while there's something inside the process to run and its valid:
		//actually, only add if its a valid job
		//use the boolean provided?
		is_valid_job_on_cpu = true;
		cpu->get_process_off_core();

		//take the last process off the core before putting on the new one, make sure there's no process there
		cpu->put_process_on_core(process);
		}

//		if (isValidJobOnCPU() == false){
//			cpu->put_process_on_core(process);
//		}


	//is CPU idle or working
	bool Dispatcher::isValidJobOnCPU(){
		//check how to find out the state, and if its empty
		//double check if it's this simple with prof
		//just use boolean provided on the header file

		return is_valid_job_on_cpu;
	}


