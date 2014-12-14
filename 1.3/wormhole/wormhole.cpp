/* 
ID: vedaad71 
PROG: wormhole
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#define MAX_N 12

int x[MAX_N+1];
int y[MAX_N+1];
int n;
int partner[MAX_N+1];
int nextRight[MAX_N+1];

int checkCycle() {
    int next;

    for (int i = 1; i <= n; i++) {
	next = i;
	for (int j = 1; j <= n; j++) {
	    next = partner[nextRight[next]];
	}
	if (next != 0) return true;
    }
    return false;

    return 0;
}

int check() {
    int i, count = 0;
    for (i = 1; i <= n; i++) 
	if (partner[i] == 0) break;

    if (i > n) return checkCycle();
    
    for (int j = i+1; j <= n; j++) {
	if (partner[j] == 0) {
	    partner[j] = i;
	    partner[i] = j;
	    count += check();
	    partner[j] = partner[i] = 0;
	}
    }

    return count;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
  
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= n; j++) {
	    if (y[i] == y[j] && x[j] > x[i] &&
		(nextRight[i] == 0 || x[j] < x[nextRight[i]]))
		nextRight[i] = j;
	}
    }

    cout << check() << endl;
    return 0;
}
