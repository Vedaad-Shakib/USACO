/* 
ID: vedaad71 
PROG: cowjog
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX_N 100000

int speeds[MAX_N+1];
int heads[MAX_N+1]; // the head of group the cow is in
int tmp;
int n;
int nGroups = 1;

int main() {
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
  
    cin >> n;
    
    for (int i = 0; i < n; i++) {
	cin >> tmp >> speeds[i];
    }

    heads[n-1] = n-1;
    for (int i = n-2; i >= 0; i--) {
	if (speeds[i] > speeds[i+1]) heads[i] = heads[i+1];
	else if (speeds[i] > speeds[heads[i+1]]) heads[i] = heads[i+1];
	else {
	    heads[i] = i;
	    nGroups++;
	}
	    
    }

    cout << nGroups << endl;
    return 0;
}
