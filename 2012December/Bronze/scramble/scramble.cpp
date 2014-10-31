#include <iostream>
#include <string>
#include <algorithm>

#define debug(a) cout << #a << ": " << (a) << endl;

using namespace std;

string names[50000];
string low[50000];
string high[50000];
int n;
string tmp;
int tmpHigh;
int tmpLow;
string st;

int findIndex(string value) {
  for (int i = 0; i < n; i++) {
    if (low[i] == value)
      return i;
  }
  return 5000000;
}
// assumes sorted array
int findLow(string tmp, int l, int r) {
  if (r - l < 2) {
    if (high[l].compare(tmp) > 0) return l;
    if (high[r].compare(tmp) < 0) return r+1;
    if (high[l].compare(tmp) < 0 && high[r].compare(tmp) > 0) return r;
    if (high[l].compare(tmp) == 0) return l;
    if (high[r].compare(tmp) == 0) return r;
  }

  int mid = l+(r-l)/2;

  if (high[mid].compare(tmp) == 0) return mid;
  if (high[mid].compare(tmp) < 0) return findLow(tmp, mid, r);
  if (high[mid].compare(tmp) > 0) return findLow(tmp, l, mid);
}

// assumes sorted array
int findHigh(string tmp, int l, int r) {
  if (r - l < 2) {
    if (low[l].compare(tmp) > 0) return l;
    if (low[r].compare(tmp) < 0) return r+1;
    if (low[l].compare(tmp) < 0 && low[r].compare(tmp) > 0) return r;
    if (low[l].compare(tmp) == 0) return l;
    if (low[r].compare(tmp) == 0) return r;
  }

  int mid = l+(r-l)/2;

  if (low[mid].compare(tmp) == 0) return mid;
  if (low[mid].compare(tmp) < 0) return findHigh(tmp, mid, r);
  if (low[mid].compare(tmp) > 0) return findHigh(tmp, l, mid);
}

int main() {
  freopen("scramble.in", "r", stdin);
  freopen("scramble.out", "w", stdout);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> names[i];
  }
   
  for (int i = 0; i < n; i++) {
    tmp = names[i];
    sort(tmp.begin(), tmp.end());
    low[i] = tmp;
    reverse(tmp.begin(), tmp.end());
    high[i] = tmp;
  }
  
  sort(low, low+n);
  sort(high, high+n);

  // binary search for the correct position
  for (int i = 0; i < n; i++) {
    tmp = names[i];
    sort(tmp.begin(), tmp.end());
    tmpLow = findLow(tmp, 0, n-1);
    st = tmp;

    reverse(tmp.begin(), tmp.end());
    tmpHigh = findHigh(tmp, 0, n-1);
    if (tmpHigh > findHigh(st, 0, n-1)) tmpHigh--; // the original is still be in the array

    cout << tmpLow+1 << " " << tmpHigh+1 << endl;
  }


  return 0;
}
