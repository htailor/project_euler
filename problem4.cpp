/******************************************************************************************

	Problem 4 - Largest palindrome product
	
	A palindromic number reads the same both ways. The largest palindrome made from the 
	product of two 2-digit numbers is 9009 = 91 × 99.

	Find the largest palindrome made from the product of two 3-digit numbers.

*******************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <runtime.hpp>

bool isPalindrome(const int &x){

	std::stringstream ss;
	ss << x;
	std::string number = ss.str();
	
	std::string::iterator it = number.begin();
	std::string::reverse_iterator rit = number.rbegin();

	while(it != number.end()){
		if(*it != *rit){
			return false;
		}
		it++;
		rit++;
	}

	return true;
}

int Answer1(const int &number_size){

	int upper_bound = pow(10,number_size)-1;
	int lower_bound = pow(10,number_size-1);

	int max_palindrome = 0;
	int num1 = 0;
	int num2 = 0;

	for(int i = upper_bound; i >= lower_bound; i--){
		for(int j = upper_bound; j >= lower_bound; j--){
			int num = i*j;
			if(isPalindrome(num)){
				if(num > max_palindrome){
					num1 = i;
					num2 = j;
					max_palindrome = num;
				}
			}
		}
	}
	std::cout << num1 << std::endl;
	std::cout << num2 << std::endl;
	return max_palindrome;
}


int Answer2(const int &number_size){

	int upper_bound = pow(10,number_size)-1;
	int lower_bound = pow(10,number_size-1);

	int max_palindrome = 0;
	int num1 = 0;
	int num2 = 0;

	for(int i = upper_bound; i >= lower_bound; i--){
		for(int j = i; j >= lower_bound; j--){
			int num = i*j;
			if(num < max_palindrome){
				break;
			}

			if(num > max_palindrome && isPalindrome(num)){
				num1 = i;
				num2 = j;
				max_palindrome = num;
			}
		}
	}
	std::cout << num1 << std::endl;
	std::cout << num2 << std::endl;
	return max_palindrome;
}


int main(int argc, char* argv[]){

	std::cout << "Largest palindrome product" << std::endl;
	std::cout << "==========================" << std::endl;
	
	Runtime timer;
	timer.Start();
	std::cout << "Answer: " << Answer1(3) << std::endl;
	timer.Stop();
	timer.Start();
	std::cout << "Answer: " << Answer2(3) << std::endl;
	timer.Stop();
	
	return 0;
}
