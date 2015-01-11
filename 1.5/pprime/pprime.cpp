/* 
ID: vedaad71 
PROG: pprime
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

int a;
int b;
int maxDigits;
int num;

bool isPrime(int num) {
    if (num == 2) return true;
    
    for (int i = 2; i < sqrt(num)+1; i++) {
	if (num % i == 0) return false;
    }
    return true;
}

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);

    cin >> a >> b;
    int maxDigits = ceil(log10(b));

    // one digit
    if (maxDigits >= 1) {
	for (int i = 1; i < 10; i += 2) {
	    num = i;
	    if (num >= a && num <= b && isPrime(num)) cout << num << endl;
	}
    }

    // two digits
    if (maxDigits >= 2) {
	for (int i = 1; i < 10; i += 2) {
	    num = 10*i + i;
	    if (num >= a && num <= b && isPrime(num)) cout << num << endl;
	}
    }

    if (maxDigits >= 3) {
	for (int i = 1; i < 10; i += 2) {
	    for (int j = 0; j < 10; j++) {
		num = 100*i + 10*j + i;
		if (num >= a && num <= b && isPrime(num)) cout << num << endl;
	    }
	}
    }

    if (maxDigits >= 4) {
	for (int i = 1; i < 10; i += 2) {
	    for (int j = 0; j < 10; j++) {
		num = 1000*i + 100*j + 10*j + i;
		if (num >= a && num <= b && isPrime(num)) cout << num << endl;
	    }
	}
    }

    if (maxDigits >= 5) {
	for (int i = 1; i < 10; i += 2) {
	    for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
		    num = 10000*i + 1000*j + 100*k + 10*j + i;
		    if (num >= a && num <= b && isPrime(num)) cout << num << endl;
		}
	    }
	}
    }

    if (maxDigits >= 6) {
	for (int i = 1; i < 10; i += 2) {
	    for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
		    num = 100000*i + 10000*j + 1000*k + 100*k + 10*j + i;
		    if (num >= a && num <= b && isPrime(num)) cout << num << endl;
		}
	    }
	}
    }

    if (maxDigits >= 7) {
	for (int i = 1; i < 10; i += 2) {
	    for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
		    for (int l = 0; l < 10; l++) {
			num = 1000000*i + 100000*j + 10000*k + 1000*l + 100*k + 10*j + i;
			if (num >= a && num <= b && isPrime(num)) cout << num << endl;
		    }
		}
	    }
	}
    }

    if (maxDigits >= 8) {
	for (int i = 1; i < 10; i += 2) {
	    for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
		    for (int l = 0; l < 10; l++) {
			num = 10000000*i + 1000000*j + 100000*k + 10000*l + 1000*l + 100*k + 10*j + i;
			if (num >= a && num <= b && isPrime(num)) cout << num << endl;
		    }
		}
	    }
	}
    }
    
    return 0;
}
