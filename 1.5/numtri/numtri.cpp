/* 
ID: vedaad71 
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

int r;
int maxSum = 0;
int curr;
int triangle[1010][1010];

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    cin >> r;
    
    for (int i = 0; i < r; i++) {
	for (int j = 0; j < i+1; j++) {
	    cin >> triangle[i][j];
	}
    }
    
    for (int i = 1; i < r; i++) {
	for (int j = 0; j < i+1; j++) {
	    if (j == 0) triangle[i][j] += triangle[i-1][j];
	    else if (j == i) triangle[i][j] += triangle[i-1][j-1];
	    else triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
	}
    }

    for (int j = 0; j < r; j++) maxSum = max(triangle[r-1][j], maxSum);

    cout << maxSum << endl;
    return 0;
}
