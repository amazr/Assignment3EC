#include <iostream>
#include <vector>
using namespace std;

void flagNonPrimes(vector<bool> &sieve, int inner, int increment) {

	if (inner < sieve.size()) {
		sieve[inner] = false;
		flagNonPrimes(sieve, inner + increment, increment);
	}

}

void findPrimes(vector<bool> &sieve, int outer) {

	if (sieve[outer]) {
		flagNonPrimes(sieve, 2 * outer, outer);
	}

	if (outer * outer < sieve.size()) {
		findPrimes(sieve, outer + 1);
	}
}

void displayPrimes(vector<bool> sieve) {

	cout << endl << "These are all of the prime numbers less than " << sieve.size() << ":";
	for (int i = 0; i < sieve.size(); i++) {
		if (i % 50 == 0) {
			cout << endl;
		}
		if (sieve[i]) {
			cout << i << " ";
		}
	}
	cout << endl << endl;
}


int main() {

	int L;
	cout << "What is the upper range of numbers you'd like to search for prime-ness: ";
	cin >> L;

	vector<bool> sieve(L, true);
	sieve[0] = false;
	sieve[1] = false;

	findPrimes(sieve, 2);
	displayPrimes(sieve);
}