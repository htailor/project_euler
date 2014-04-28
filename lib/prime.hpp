#ifndef _PRIME_
#define _PRIME_

bool isPrime(unsigned int &x){

	for(int i = 2; i < x; i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

#endif
