/******************************************************************************************

	Problem 5 - Smallest multiple
	
	2520 is the smallest number that can be divided by each of the numbers from 1 to 10
	without any remainder.

	What is the smallest positive number that is evenly divisible by all of the numbers
	from 1 to 20?

*******************************************************************************************/

#include <iostream>
#include <cmath>
#include <runtime.hpp>

bool isPrime(const int &x){

	/*
	 *	Apart from numbers 2 and 3, all other prime numbers are
	 *	determined from 6k +/- 1, where k is a real integer.
	 *
	 */

	if(x == 2 || x == 3 || (x - 1) % 6 == 0 || (x + 1) % 6 == 0 ){
		return true;
	}

	return false;
}

unsigned int FindLowestPrimeFactor(const unsigned int &x){

	unsigned int lowest_prime_factor = 1;

	for(unsigned int i = 2; i <= x; i++){
		if(x % i==0 && isPrime(i)){
			lowest_prime_factor = i;
			break;
		}
	}
	return lowest_prime_factor;
}


unsigned int Answer1(const unsigned int &x){

	unsigned int smallest_multiple = 1;

	for(unsigned int i = 2; i <= x; i++){
		int r = smallest_multiple % i;
		if(r==0){
			// if r==0 then i is already a multiple
		}
		else if(r!=0 && isPrime(i)){ 
			smallest_multiple = smallest_multiple * i;
		}
		else{
			smallest_multiple = smallest_multiple * FindLowestPrimeFactor(r);
		}
	}
	return smallest_multiple;
}

unsigned int Answer2(const int &x){

	unsigned int smallest_factor = 1;
	double logx = log(x);

	for(unsigned int i = 2; i <= 20; i++){
		if(isPrime(i)){
			smallest_factor = smallest_factor * pow(i, static_cast<int>(std::floor(logx/log(i))));
		}
	}

	return smallest_factor;
}

int main(int argc, char* argv[]){

	std::cout << "Smallest multiple" << std::endl;
	std::cout << "=================" << std::endl;
	
	Runtime timer;

	int x = 20;
	timer.Start();
	std::cout << "Answer: " << Answer1(x) << std::endl;
	timer.Stop();

	timer.Start();
	std::cout << "Answer: " << Answer2(x) << std::endl;
	timer.Stop();
	
	return 0;
}
