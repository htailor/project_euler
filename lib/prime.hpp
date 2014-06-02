#ifndef _PRIME_
#define _PRIME_

#include <cmath>

bool isPrime(unsigned int &x){
	if(x==2){ return true; }
	if(x!=2 && x%2==0){ return false; }
	for(int i = 3; i <= std::floor(sqrt(x)); i=i+2){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}
#endif
