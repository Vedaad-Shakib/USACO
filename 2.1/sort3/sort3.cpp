/* 
ID: vedaad71 
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <bitset>
#include <vector>
#include <functional>
#include <queue>
#include <map>

#define MAX_N 1000

using namespace std;

int n;
int vals[MAX_N+1];
int nums[3]; // number of 1s, 2s, and 3s
int numIn1[3]; // number of 2s and 3s in the 1s zone
int numIn2[3]; 
int numIn3[3]; 
int switches = 0;

int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
	cin >> vals[i];
	vals[i]--; // convert to 0, 1, and 2
	nums[vals[i]]++;
    }

    for (int i = 0; i < nums[0]; i++) {
	numIn1[vals[i]]++;
    }
    for (int i = nums[0]; i < nums[1]+nums[0]; i++) {
	numIn2[vals[i]]++;
    }
    for (int i = nums[0]+nums[1]; i < nums[0]+nums[1]+nums[2]; i++) {
	numIn3[vals[i]]++;
    }

    int tmp = min(numIn1[1], numIn2[0]); // switch 1s and 2s
    switches += tmp;
    numIn1[1] -= tmp;
    numIn2[0] -= tmp;

    tmp = min(numIn1[2], numIn3[0]); // switch 1s and 3s
    switches += tmp;
    numIn1[2] -= tmp;
    numIn3[0] -= tmp;

    tmp = min(numIn2[2], numIn3[1]); // switch 2s and 3s
    switches += tmp;
    numIn2[2] -= tmp;
    numIn3[1] -= tmp;
    
    switches += 2*numIn1[1] + 2*numIn1[2]; // leftover numbers need to be cycled: 2 operations per cycle

    cout << switches << endl;

    return 0;
}
