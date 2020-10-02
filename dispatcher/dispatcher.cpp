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
		if (isValidJobOnCPU()){
			return cpu->get_process_off_core();

		}
		else{
			return PCB();
		}
	}

	//place the current process on the CPU for execution
	//look at CPU.h for its methods
	void Dispatcher::put_on_CPU(PCB  &process){

		//while there's something inside the process to run and its valid:
		if (process.isEmpty() == false){
			cpu->put_process_on_core(process);
		}
		if (isValidJobOnCPU() == false){
			cpu->put_process_on_core(process);
		}
	}

	//is CPU idle or working
	bool Dispatcher::isValidJobOnCPU(){
		//check how to find out the state, and if its empty
		//double check if it's this simple with prof
		return cpu->get_COPY_of_Current_Process().isEmpty();
	}


