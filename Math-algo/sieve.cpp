// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes

#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n) {
    // Create a boolean vector to mark numbers as prime or composite
    vector<bool> isPrime(n + 1, true);

    // 0 and 1 are not prime
    isPrime[0] = isPrime[1] = false;

    // Iterate over all numbers from 2 to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        // If i is prime, mark its multiples as composite
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print prime numbers
    cout << "Prime numbers up to " << n << " are: ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the upper limit: ";
    cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}


