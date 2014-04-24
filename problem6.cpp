/******************************************************************************************

	Problem 6 - Sum square difference

	The sum of the squares of the first ten natural numbers is,

		1^2 + 2^2 + ... + 10^2 = 385

	The square of the sum of the first ten natural numbers is,

		(1 + 2 + ... + 10)^2 = 55^2 = 3025

	Hence the difference between the sum of the squares of the first ten natural numbers 
	and the square of the sum is 3025 − 385 = 2640.

	Find the difference between the sum of the squares of the first one hundred natural 
	numbers and the square of the sum.

*******************************************************************************************/

#include <iostream>
#include <cmath>
#include <runtime.hpp>

int Answer1(const int &n){

	int sum_of_squares = 0;
	int square_of_sum = 0;
	for(unsigned int i = 0; i <= n; i++){
		sum_of_squares = sum_of_squares + pow(i,2);
		square_of_sum = square_of_sum + i;
	}

	return pow(square_of_sum,2)-sum_of_squares;	
}

int Answer2(const int &n){

	int sum_of_squares = n*(n+1)*(2*n+1)/6;
	int square_of_sum = n*(n+1)/2;

	return pow(square_of_sum,2)-sum_of_squares;	
}

int main(int argc, char* argv[]){

	std::cout << "Sum square difference" << std::endl;
	std::cout << "=====================" << std::endl;
	
	Runtime timer;
	timer.Start();
	std::cout << "Answer: " << Answer1(200) << std::endl;
	timer.Stop();
	timer.Start();
	std::cout << "Answer: " << Answer2(200) << std::endl;
	timer.Stop();
	
	return 0;
}
