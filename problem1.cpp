/******************************************************************************************

	Problem 1 - Multiples of 3 and 5
	
	If we list all the natural numbers below 10 that are multiples of 3 or 5, we get
	3, 5, 6 and 9. The sum of these multiples is 23. 
	
	Find the sum of all the multiples of 3 or 5 below 1000.

*******************************************************************************************/

#include <iostream>
#include <cmath>
#include <runtime.hpp>

int Problem1(const int &x){

	int sum = 0;
	for(int i = 0; i < x; i++){
		if( i % 3 == 0 || i % 5 == 0){
			sum = sum + i;
		}
	}
	return sum;
}

int MultipleSum(int x, int multiple){
	x = std::floor((x-1)/multiple);
	return multiple*x*(x+1)/2;
}

int AnalyticalProblem1(int x){
	return MultipleSum(x,3) + MultipleSum(x,5) - MultipleSum(x,15);
}


int main(int argc, char* argv[]){

	std::cout << "Multiples of 3 and 5" << std::endl;
	std::cout << "====================" << std::endl;

	Runtime timer;
		
	//int upper_bound = 1000;
	int upper_bound = 1000000000;
	
	timer.Start();
	std::cout << "Answer: " << Problem1(upper_bound) << std::endl;	
	timer.Stop();
	
	timer.Start();
	std::cout << "Answer: " << AnalyticalProblem1(upper_bound) << std::endl;	
	timer.Stop();
	
	
	
	
	return 0;
}
