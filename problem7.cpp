/******************************************************************************************

	Problem 7 - 10001st prime

	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the
	6th prime is 13.

	What is the 10001st prime number?

*******************************************************************************************/

#include <iostream>
#include <prime.hpp>
#include <runtime.hpp>

int Answer1(const int &nth_prime){

	unsigned int count = 1;
	unsigned int number = 3;
	unsigned int prime_number = 2;

	while(count < nth_prime){
		if(isPrime(number)){
			count++;
			prime_number = number;
		}
		number = number + 2;
	}
	return prime_number;
}


int main(int argc, char* argv[]){

	std::cout << "10001st prime" << std::endl;
	std::cout << "=============" << std::endl;

	Runtime timer;
	timer.Start();
	std::cout << "Answer: " << Answer1(10001) << std::endl;
	timer.Stop();

	return 0;
}
