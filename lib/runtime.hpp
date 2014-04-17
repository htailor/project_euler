#ifndef _RUNTIME_
#define _RUNTIME_

#include <iostream>
#include <ctime>

class Runtime{

	public:
		void Start();
		void Stop();
	
	private:
		unsigned int start_time;
		unsigned int stop_time;
};

void Runtime::Start(){
	start_time = clock();
}

void Runtime::Stop(){
	stop_time = clock();
	double cpu_time = static_cast<double>(stop_time - start_time); 
	double run_time = cpu_time/CLOCKS_PER_SEC; 
	std::cout << "--> Runtime: " << run_time << " sec" << std::endl;
	std::cout << "--> CPUtime: " << cpu_time << std::endl;
}

#endif