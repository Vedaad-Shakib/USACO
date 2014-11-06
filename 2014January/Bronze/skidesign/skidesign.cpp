#include<iostream>
#include<algorithm>

using namespace std;

int heights[1000];
int n;
int minPrice = 300000000;
int currPrice;

int main() {
  freopen("skidesign.in", "r", stdin);
  freopen("skidesign.out", "w", stdout);

  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }
  
  for (int i = 0; i < 100-17; i++) {
    currPrice = 0;

    for (int j = 0; j < n; j++) {
      if (heights[j] < i) currPrice += (i-heights[j])*(i-heights[j]);
      if (heights[j] > i+17) currPrice += (heights[j]-i-17)*(heights[j]-i-17);
    }
    minPrice = min(minPrice, currPrice);
  }

  cout << minPrice << endl;
  return 0;
}
