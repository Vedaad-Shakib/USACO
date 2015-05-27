/* 
ID: vedaad71 
PROG: subset
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

long long n;
long long a; // sum 1
long long b; // sum 2
long long dp[40][40*41/2]; // how many ways to form the sum i with set of numbers from 1 through n

long long count(long long num) {
    if (num <= 0) {
	if (a == b) return 1;
	else return 0;
    }

    if (dp[num][abs(b-a)] != -1) return dp[num][abs(b-a)];

    long long tmp = 0;
    a += num;
    tmp += count(num-1);
    a -= num;

    b += num;
    tmp += count(num-1);
    b -= num;

    dp[num][abs(b-a)] = tmp;

    return tmp;
}

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    cin >> n;

    for (long long i = 0; i < 39; i++) {
	for (long long j = 0; j < 40*41/2+1; j++) {
	    dp[i][j] = -1;
	}
    }
    
    cout << count(n)/2 << endl;
    
    return 0;
}
