/* 
ID: vedaad71 
PROG: marathon
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#define MAX_N 100000

int x[MAX_N+1];
int y[MAX_N+1];
int n;
int shortest = -1;
int tmp;
int skipIndex;

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

// how much distance you're skipping
int checkDelta(int skip) {
    return dist(x[skip-1], y[skip-1], x[skip], y[skip]) + dist(x[skip], y[skip], x[skip+1], y[skip+1]) - dist(x[skip-1], y[skip-1], x[skip+1], y[skip+1]);
}

int calcDistance(int skip) {
    int total = 0;
    for (int i = 0; i < n-1; i++) {
	if (i+1 == skip) {
	    total += dist(x[i], y[i], x[i+2], y[i+2]);
	    i++;
	} else {
	    total += dist(x[i], y[i], x[i+1], y[i+1]);
	}
    }

    return total;
}

int main() {
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
  
    cin >> n;

    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    for (int i = 1; i < n-1; i++) {
	tmp = checkDelta(i);
	if (shortest == -1 || tmp > shortest) {shortest = tmp; skipIndex = i;}
    }
    
    shortest = calcDistance(skipIndex);
    tmp = calcDistance(-1);
    if (tmp < shortest) shortest = tmp;

    cout << shortest << endl;
    return 0;
}
