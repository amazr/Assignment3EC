#include <iostream>
using namespace std;

void setAr(bool ar[], int L) {
	for (int i = 0; i < L; i++) {
		if (i < 2) {
			ar[i] = false;
		}
		else {
			ar[i] = true;
		}
	}
}

void findPrimes(bool ar[], int n, int L) {

	if (ar[n]) {
		for (int i = n * 2; i < L; i += n) {
			ar[i] = false;
		}
	}

	if (n * n < L) {
		findPrimes(ar, n + 1, L);
	}
}

void displayPrimes(bool ar[], int L) {
	for (int i = 0; i < L; i++) {
		if (ar[i]) {
			cout << i << " is prime." << endl;
		}
		else {
			cout << i << " is not prime." << endl;
		}
	}
}


int main() {
	int L = 100;
	bool ar[100];

	setAr(ar, L);
	findPrimes(ar, 2, L);
	displayPrimes(ar, L);
	
	return 0;
}