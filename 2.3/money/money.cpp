/*                                                                                                                                                                                                                                         
ID: vedaad71                                                                                                                                                                                                                               
PROG: money
LANG: C++11                                                                                                                                                                                                                                
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

#define MAX_V 25
#define MAX_N 10000

long long nCoins = 0;
long long currSum = 0;
long long n;
long long v;
long long coins[MAX_V+1];
long long dp[MAX_N+1][MAX_V+1];

long long combinations(long long m) {
    if (m >= v) return 0;
    if (nCoins == 0) return 1;
    if (nCoins <= 0) return 0;

    if (dp[nCoins][m] != -1) return dp[nCoins][m];

    long long tmp = 0;
    nCoins -= coins[m];
    tmp += combinations(m);
    nCoins += coins[m];

    tmp += combinations(m+1);

    dp[nCoins][m] = tmp;

    return tmp;
}

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);

    cin >> v >> n;

    nCoins = n;

    for (long long i = 0; i < v; i++) {
	cin >> coins[i];
    }

    for (long long i = 0; i < n+1; i++) {
	for (long long j = 0; j < v+1; j++) {
	    dp[i][j] = -1;
	}
    }

    cout << combinations(0) << endl;

    return 0;
}
