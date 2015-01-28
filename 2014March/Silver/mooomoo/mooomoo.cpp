#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <bitset>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define debug(a) cout << #a << ": " << (a) << endl;
#define MAX_V 100000
#define MAX_B 20
#define MAX_N 100

int n;
int b;
int volumes[MAX_V+1];
int breeds[MAX_B+1];
int fields[MAX_N+1];
int nCows = 0;

// calculates the minimum cows required to reach a certain volume
int volume(int vol) {
    int minCows = MAX_V+1; // "infinity"
    if (vol < 0) return MAX_V+1; // "infinity"
    if (vol == 0) return 0;
    if (volumes[vol] != -1) return volumes[vol];
    else for (int i = 0; i < b; i++) minCows = min(minCows, 1+volume(vol-breeds[i]));

    volumes[vol] = minCows;
    return minCows;
}

int main() {
  freopen("mooomoo.in", "r", stdin);
  freopen("mooomoo.out", "w", stdout);

  cin >> n >> b;

  fill_n(volumes, MAX_V+1, -1);

  for (int i = 0; i < b; i++) cin >> breeds[i];
  for (int i = 0; i < n; i++) cin >> fields[i];

  // get the volume added by cow mooing in each field and find the minimum
  // amount of cows which could have caused the mooing
  for (int i = 0; i < n; i++) {
      if (n == 0) nCows += volume(fields[i]);
      else nCows += volume(fields[i] - ((fields[i-1] != 0) ? (fields[i-1] - 1) : 0));
  }

  cout << nCows << endl;

  return 0;
}



