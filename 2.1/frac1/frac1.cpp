/* 
ID: vedaad71 
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

#define MAX_N 160

using namespace std;

struct frac {
    int num;
    int den;
    double val;
};

int n;
int nFractions = 2;
frac fractions[MAX_N*MAX_N+1];

bool compare(frac const &a, frac const &b) {
    return a.val < b.val;
}

bool isReduced(int a, int b) {
    if (b == 1) return true;

    for (int i = 2; i < min(a, b) + 1; i++) {
	if (a%i == 0 && b%i == 0) return false;
    }
    return true;
}

int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);

    cin >> n;

    fractions[0] = (frac) {0, 1, 0};
    fractions[1] = (frac) {1, 1, 1};
    for (int i = 2; i < n+1; i++) {
	for (int j = 1; j < i; j++) {
	    if (!isReduced(i, j)) continue;
	    frac temp = {j, i, (double)j/i};
	    fractions[nFractions] = temp;
	    nFractions++;
	}
    }

    sort(fractions, fractions+nFractions, &compare);

    for (int i = 0; i < nFractions; i++)
	cout << fractions[i].num << "/" << fractions[i].den << endl;

    return 0;
}
