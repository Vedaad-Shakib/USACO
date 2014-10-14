#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;

#define debug(a) cout << #a << ": " << (a) << endl;

bool done[100];
int a[100];
int b[100];

int findB(int i) {
  for (int j = 0; j < sizeof(b)/sizeof(b[0]); j++) {
    if (b[j] == i) {
      return j;
    }
  }

  return -1;
}

int cycle(int i) {
  if (a[i] == b[i])
  {
    done[i] = true;
    return 1;
  }
  else
  {

    int temp = findB(a[i]);
    int tempValue = a[temp];
    a[temp] = a[i];
    a[i] = tempValue;
    done[temp] = true;
    return 1 + cycle(i);
  }
}

int main() {
  freopen("reorder.in", "r", stdin);
  freopen("reorder.out", "w", stdout);
  
  int n;
  int max = -1;
  int cycleLength = 0;
  int counter = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < n; i++) {
    if (!done[i]) {
      cycleLength = cycle(i);

      if (cycleLength == 1) { // there can't be a one cow cyclic shift
	continue;
      }

      counter++;

      if (cycleLength > max) {
	max = cycleLength;
      }
    }
  }

  cout << counter << " " << max << endl;
  return 0;
}



