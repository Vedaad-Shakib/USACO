/* 
ID: vedaad71 
PROG: learning
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX_N 50000
int n;
int a;
int b;
pair<int, bool> cows[MAX_N+1];
pair<int, bool> tmp;
string spotted;
int weight;
int nSpotted = 0;
int high;
int low;

int main() {
    freopen("learning.in", "r", stdin);
    freopen("learning.out", "w", stdout);
  
    cin >> n >> a >> b;
    
    for (int i = 0; i < n; i++) {
	cin >> spotted >> weight;
	tmp.first = weight;
	tmp.second = (spotted.compare("S") == 0) ? true : false;
	cows[i] = tmp;
    }

    sort(cows, cows+n);

    for (int i = 0; i < n; i++) {
	// get the low and high of the interval of influence of the current cow
	// (halfway between previous cow and current cow to halfway between current cow and next cow)
	if (i == 0) low = min(cows[i].first, a);
	else low = (cows[i-1].first + cows[i].first)/2 + 1;
	
	if (i == n-1) high = max(cows[i].first, b);
	else {
	    high = (cows[i+1].first + cows[i].first)/2;
	    if ((cows[i+1].first + cows[i].first)%2 == 0) high--; // we deal with the midpoint separately
	}

	// cout << "i: " << i << " low: " << low << " high: " << high << endl;

	// midpoint of previous and current depends on both, so we have a separate case for that
	if (i != 0) {
	    int sum = cows[i-1].first + cows[i].first;
	    if (sum%2 == 0 && a <= sum/2 && b >= sum/2) {
		nSpotted += (cows[i-1].second || cows[i].second);
	    }
	}

	if (a > high || b < low) continue;

	// how many cows are in the interval (max and min account for a and b limits)
	low = max(low, a);
	high = min(high, b);
	nSpotted += cows[i].second * (high-low+1);
    }

    cout << nSpotted << endl;

    return 0;
}
