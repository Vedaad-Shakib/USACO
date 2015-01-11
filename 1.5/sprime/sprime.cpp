/* 
ID: vedaad71 
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

int n;

bool isPrime(int num) {
    if (num == 2) return true;
    
    for (int i = 2; i < sqrt(num)+1; i++) {
	if (num % i == 0) return false;
    }
    return true;
}

void addPrime(int num) {
    if (!isPrime(num)) return;
    if (num > pow(10, n)) return;

    if (num < pow(10, n) && num > pow(10, n-1)) cout << num << endl;
    else {
	addPrime(10*num+1);
	addPrime(10*num+3);
	addPrime(10*num+7);
	addPrime(10*num+9);
    }
}

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);

    cin >> n;

    addPrime(2);
    addPrime(3);
    addPrime(5);
    addPrime(7);

    return 0;
}
