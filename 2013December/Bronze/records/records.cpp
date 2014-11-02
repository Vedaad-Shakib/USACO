#include <iostream>
#include <algorithm>

using namespace std;

string names[1000];
int n;
int high = 1;
int current = 1;

int main() {
  freopen("records.in", "r", stdin);
  freopen("records.out", "w", stdout);

  cin >> n;

  for (int i = 0; i < n; i++) {
    string tmp[3];
    cin >> tmp[0] >> tmp[1] >> tmp[2];
    sort(tmp, tmp+3);
    names[i] = tmp[0] + " " + tmp[1] + " " + tmp[2];
  }
  
  sort(names, names+n);

  for (int i = 1; i < n; i++) {
    if (names[i] == names[i-1]) current++;
    else {
      high = max(current, high);
      current = 1;
    }
  }

  high = max(current, high);

  cout << high << endl;

  return 0;
}
