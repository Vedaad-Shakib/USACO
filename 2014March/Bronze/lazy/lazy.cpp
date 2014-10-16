#include <iostream>      
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << (a) << endl;

struct grass {
  int location;
  int nGrasses;
};

bool compare(const grass &a, const grass &b) {
  return a.location < b.location;
}

int main() {
  freopen("lazy.in", "r", stdin);
  freopen("lazy.out", "w", stdout);

  int n, k, maxGrasses = 0, rightIndex, leftIndex = 0, nCurrentGrasses = 0;
  struct grass tempGrass;
  //struct grass *grasses;
  cin >> n >> k;
  struct grass grasses[n];

  //grasses = (struct grass *) malloc(sizeof(grass) * n);

  for (int i = 0; i < n; i++) {
    struct grass temp;
    cin >> temp.nGrasses >> temp.location;
    grasses[i] = temp;
  }

  sort(grasses, grasses+n, compare);
  
  // get initial nRightGrasses
  for (rightIndex = 0; rightIndex < n && grasses[rightIndex].location <= k * 2; rightIndex++) {
    nCurrentGrasses += grasses[rightIndex].nGrasses;
  }

  // iterate through and check greedily
  for (int i = k; rightIndex < n; i++) {

    if (i - grasses[leftIndex].location > k) {
      nCurrentGrasses -= grasses[leftIndex].nGrasses;
      leftIndex++;
    }

    if (grasses[rightIndex].location - i <= k) {
      nCurrentGrasses += grasses[rightIndex].nGrasses;
      rightIndex++;
    }

    if (nCurrentGrasses > maxGrasses)
      maxGrasses = nCurrentGrasses;
  }

  cout << maxGrasses << endl;

  return 0;
}
