/*
Binary Exponentiation or Exponentiation by squaring is the process of calculating a number raised to the power another number (AB) in Logarithmic time of the exponent or power, which speeds up the execution time of the program.

Whenever we need to calculate (AB), we can simple calculate the result by taking the result as 1 and multiplying A for exactly B times. The time complexity for this approach is O(B) and will fail when values of B in order of 108 or greater. This is when we can use Binary exponentiation because it can calculate the result in O(log(B)) time complexity, so we can easily calculate the results for larger values of B in order of 1018 or less.

When we are calculating (AB), we can have 3 possible positive values of B:

Case 1: If B = 0, whatever be the value of A, our result will be 1.
Case 2: If B is an even number, then instead of calculating (AB), we can calculate ((A2)B/2) and the result will be same.
Case 3: If B is an odd number, then instead of calculating (AB), we can calculate (A * (A(B – 1)/2)2),

*/


#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b) {
    long long result = 1;
    while(b) {
        if (b & 1) 
        result = result * a;
        a = a * a;
        b >>= 1;
    }
    return result;
}

int main() {
    int n, p;
    cin >> n;
    cin >> p;

    cout << power(n, p)<< endl;

    return 0;
}

//function that handles modular exponentiation:

#include <iostream>

using namespace std;

long long power(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod; // Ensure that a is within the modulus

    while (b > 0) {
        if (b & 1) { // Check if the current bit of the exponent is 1
            result = (result * a) % mod; // Multiply and take modulo
        }
        a = (a * a) % mod; // Square a and take modulo
        b >>= 1; // Move to the next bit of the exponent
    }

    return result;
}

int main() {
    int n, p;
    long long mod;
    cin >> n;
    cin >> p;
    cin >> mod;

    long long result = power(n, p, mod);
    cout << "Result: " << result << endl;

    return 0;
}

