/******************************************************************************************

	Problem 8 - Largest product in a series

	The four adjacent digits in the 1000-digit number that have the greatest product are
	9 × 9 × 8 × 9 = 5832.

		73167176531330624919225119674426574742355349194934
		96983520312774506326239578318016984801869478851843
		85861560789112949495459501737958331952853208805511
		12540698747158523863050715693290963295227443043557
		66896648950445244523161731856403098711121722383113
		62229893423380308135336276614282806444486645238749
		30358907296290491560440772390713810515859307960866
		70172427121883998797908792274921901699720888093776
		65727333001053367881220235421809751254540594752243
		52584907711670556013604839586446706324415722155397
		53697817977846174064955149290862569321978468622482
		83972241375657056057490261407972968652414535100474
		82166370484403199890008895243450658541227588666881
		16427171479924442928230863465674813919123162824586
		17866458359124566529476545682848912883142607690042
		24219022671055626321111109370544217506941658960408
		07198403850962455444362981230987879927244284909188
		84580156166097919133875499200524063689912560717606
		05886116467109405077541002256983155200055935729725
		71636269561882670428252483600823257530420752963450

	Find the thirteen adjacent digits in the 1000-digit number that have the greatest
	product. What is the value of this product?

*******************************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <utility>
#include <runtime.hpp>


long long Answer1(const std::string &bignum, unsigned int slide_length){

	long long greatest_product = 0;
	int num_length = bignum.length();

	for(int i = 0; i < (num_length-slide_length); i++){
		long long product_val = 1;

		for(int j = 0; j < slide_length; j++){
			product_val = product_val * (bignum[i+j] - '0');
		}

		if(product_val > greatest_product){
			greatest_product = product_val;
		}
	}

	return greatest_product;
}


std::pair <int, long long> fill_slide(const std::string &bignum, const int &slide_length, int bignum_index=0){

	long long product = 1;

	for(int i=0; i < slide_length; i++){

		int element_value = bignum[bignum_index + i] - '0';

		if(element_value==0){
			bignum_index = bignum_index + i + 1;
			product = bignum[bignum_index] - '0';
			i=0;
		}
		else{
			product = product * element_value;
		}
	}

	bignum_index = bignum_index + slide_length;

	return std::make_pair(bignum_index, product); 
}


long long Answer2(const std::string &bignum, unsigned int slide_length){
	
	int num_length = bignum.length();

	// Initially fill the slide
	std::pair<int, long long> s1 = fill_slide(bignum, slide_length);

	int bignum_index = s1.first;
	long long greatest_product = s1.second;
	long long product = s1.second;

	for(int i = bignum_index; i < num_length; i++){
	
		int element_value = bignum[i] - '0';		
		
		if(element_value==0){
			std::pair<int, long long> s2 = fill_slide(bignum,slide_length,i);
			i = s2.first-1;
			product = s2.second;
		}
		else{
			product = (product / (bignum[i-slide_length] - '0')) * element_value;
		}

		if(product > greatest_product){
			greatest_product = product;
		}
	}

	return greatest_product;
}



int main(int argc, char* argv[]){

	std::cout << "Largest product in a series" << std::endl;
	std::cout << "===========================" << std::endl;

	std::string bignum = "73167176531330624919225119674426574742355349194934"
						"96983520312774506326239578318016984801869478851843"
						"85861560789112949495459501737958331952853208805511"
						"12540698747158523863050715693290963295227443043557"
						"66896648950445244523161731856403098711121722383113"
						"62229893423380308135336276614282806444486645238749"
						"30358907296290491560440772390713810515859307960866"
						"70172427121883998797908792274921901699720888093776"
						"65727333001053367881220235421809751254540594752243"
						"52584907711670556013604839586446706324415722155397"
						"53697817977846174064955149290862569321978468622482"
						"83972241375657056057490261407972968652414535100474"
						"82166370484403199890008895243450658541227588666881"
						"16427171479924442928230863465674813919123162824586"
						"17866458359124566529476545682848912883142607690042"
						"24219022671055626321111109370544217506941658960408"
						"07198403850962455444362981230987879927244284909188"
						"84580156166097919133875499200524063689912560717606"
						"05886116467109405077541002256983155200055935729725"
						"71636269561882670428252483600823257530420752963450";

	unsigned int slide = 13;

	Runtime timer;
	timer.Start();
	std::cout << "Answer: " << Answer1(bignum, slide) << std::endl;
	timer.Stop();

	timer.Start();
	std::cout << "Answer: " << Answer2(bignum, slide) << std::endl;
	timer.Stop();

	return 0;
}
