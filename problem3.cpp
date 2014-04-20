/******************************************************************************************

	Problem 3 - Largest prime factor
	
	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143 ?

*******************************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <runtime.hpp>

bool isPrime1(const int &x){
	
	for(int i = 2; i < x; i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

bool isPrime2(const int &x){
	
	for(int i = 2; i <= std::floor(sqrt(x)); i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

bool isPrime3(const int &x){

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

int Answer1(long long &x){

	long long number = x;
	std::vector<int> primefactors;
	
	for(long long factor = 2; factor <= number; factor++){
		if(number % factor == 0 && isPrime3(factor)){
			primefactors.push_back(static_cast<int>(factor));
			std::cout << factor << std::endl;
		}
		while(number % factor == 0){
			number = number / factor;
		}
	}
	return primefactors.back();
}

int main(int argc, char* argv[]){

	std::cout << "Largest prime factor" << std::endl;
	std::cout << "====================" << std::endl;
	
	Runtime timer;

	//long long x = 13195;
	long long x = 600851475143;
	timer.Start();
	std::cout << "Answer: " << Answer1(x) << std::endl;
	timer.Stop();
	
	return 0;
}
