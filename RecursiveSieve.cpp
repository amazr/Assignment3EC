#include <iostream>
#include <vector>
using namespace std;

void flagNonPrimes(vector<bool> &sieve, int number, int increment) {
	if (number < sieve.size()) {
		sieve.at(number) = false;
		flagNonPrimes(sieve, number + increment, increment);
	}

}

void findPrimes(vector<bool> &sieve, int outer) {

	if (sieve.at(outer)) {
		flagNonPrimes(sieve, 2 * outer, outer);
	}

	if (outer * outer < sieve.size()) {
		findPrimes(sieve, outer + 1);
	}
}

void displayPrimes(vector<bool> sieve) {
	cout << endl << "These are all of the prime numbers less than " << sieve.size() << ":" << endl;
	for (int i = 0; i < sieve.size(); i++) {
		if (sieve[i]) {
			cout << i << " ";
		}
	}
	cout << endl << endl;
}


int main() {
	int L = 100;
	vector<bool> sieve(L, true);
	sieve[0] = false;
	sieve[1] = false;

	findPrimes(sieve, 2);
	displayPrimes(sieve);
}