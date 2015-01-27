#include <iostream>      
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << (a) << endl;
#define MAX_X 1000000

int grasses[MAX_X+1] = {0};
int n;
int k;
int maxGrass = 0;
int curr = 0;

int main() {
  freopen("lazy.in", "r", stdin);
  freopen("lazy.out", "w", stdout);
  
  cin >> n;
  cin >> k;

  for (int i = 0; i < n; i++) {
      int grass, pos;
      cin >> grass >> pos;
      grasses[pos] = grass;
  }

  for (int i = 0; i < 2*k && i < MAX_X; i++) {
      curr += grasses[i];
  }
  
  maxGrass = curr;

  for (int i = k; i < MAX_X-k; i++) {
      curr -= grasses[i-k-1];
      curr += grasses[i+k];
      maxGrass = max(maxGrass, curr);
  }

  cout << maxGrass << endl;

  return 0;
}
