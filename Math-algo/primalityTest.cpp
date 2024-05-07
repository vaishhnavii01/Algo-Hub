// check if a 
// number is prime 

#include <bits/stdc++.h> 
using namespace std; 

bool isPrime(int n) 
{ 
	if (n == 2 || n == 3) 
		return true; 

	if (n <= 1 || n % 2 == 0 || n % 3 == 0) 
		return false; 

	// To check through all numbers of the form 6k ± 1 
	for (int i = 5; i * i <= n; i += 6) { 
		if (n % i == 0 || n % (i + 2) == 0) 
			return false; 
	} 

	return true; 
} 


int main() 
{ 
	isPrime(11) ? cout << " true\n" : cout << " false\n"; 
	isPrime(15) ? cout << " true\n" : cout << " false\n"; 
	return 0; 
}

