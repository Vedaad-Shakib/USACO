/* 
ID: vedaad71 
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX_M 250

int n;
int m;
int nBisquares;

int bisquares[2*(MAX_M+1)*(MAX_M+1)];
bool hasSolution = false;

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    
    cin >> n;
    cin >> m;
    
    for (int p = 0; p < m+1; p++) {
	for (int q = 0; q < m+1; q++) {
	    bisquares[p*p + q*q] = 1;
      }
    }

    for (int b = 1; b < ceil((2*m*m+1) / (n-1.0)); b++) {
	for (int a = 0; a < 2*m*m - (n-1)*b + 1; a++) {
	    // cout << a << " " << b << endl;
	    for (int i = 0; i < n; i++) {
		if (!bisquares[a+b*i]) break;
		if (i == n-1) {
		    cout << a << " " << b << endl;
		    hasSolution = true;
		}
	    }
	}
    }

    if (!hasSolution) cout << "NONE" << endl;
    
    return 0;
}
