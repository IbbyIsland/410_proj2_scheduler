/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include <vector>
//only include whatever is in the header file
#include "../includes/stats.h"

	Stats::Stats(std::vector<PCB> &finished_vector){
		//take from the header file
		av_wait_time = 0.0;
		av_response_time = 0.0;
		av_turnaround_time = 0.0;
		vec = &finished_vector;
	}

	//loops thru vec, prints 1 line for each process using the following format
	//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
	//if there are 10 processes in vector, should print 10 lines
	void Stats::showAllProcessInfo(){
		//go through the vector
		for(int i = 0; i < vec->size(); i++){
			//make sure it doesn't start with "Process 0"
			//redo statement and order to print statements
		std::cout << "Process " << i + 1 << " Required CPU time:" << vec->at(i).required_cpu_time << " arrived:"
				<< vec->at(i).arrival_time << " started:" << vec->at(i).start_time << " finished:" << vec->at(i).finish_time;


		}

	}

	//after a process is placed in the ready_q, how long does
	//it take before its placed on the processor?
	//response_time per process = start_time - arrival_time
	//this funtion returns the average over all processes
	float Stats::get_av_response_time(){
		double counter = 0.0;
		//float responseTime = 0.0;
		//get the info
		for (int i = 0; i < vec->size(); i++){
			av_response_time = (vec->at(i).start_time - vec->at(i).arrival_time);
			counter = counter +  av_response_time;
		}
		//divide the response time by the size of the vector
		counter = counter/ vec->size();

		return counter;
	}

	//after a process is placed in the ready_q, how long does
	//it take to complete?
	//turnaround time per process = finish_time - arrival_time
	//this funtion returns the average over all processes
	float Stats::get_av_turnaround_time(){
		//initialize the time for every process
		double counter = 0.0;
		//float turnAroundTime = 0.0;
		//get the info
		for (int i = 0; i < vec->size(); i++){
			av_turnaround_time = (vec->at(i).finish_time - vec->at(i).arrival_time);
			counter = counter + av_turnaround_time;
		}
		//if there's nothing in the process for turnaroundTime:
		//divide the turnaroundtime by the size of the vector
			counter = counter / vec->size();

		return counter;


	}

	//after a process is placed in the ready_q, how much time does it
	//spend waiting for processor time?
	//wait time per process = finish_time - arrival_time-required_CPU_time
	//this funtion returns the average over all processes
	float Stats::get_av_wait_time(){
		double counter = 0.0;
		//float waitTime = 0.0;
		//get the info
		for (int i = 0; i < vec->size(); i++){
			av_wait_time = (vec->at(i).finish_time - vec->at(i).arrival_time - vec->at(i).required_cpu_time);
			counter += av_wait_time;
		}
		//if there's nothing in the waitTime portion:
		//divide the wait time by the size of the vector
		counter = counter/vec->size();

		return counter;

	}

