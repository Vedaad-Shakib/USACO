/* 
ID: vedaad71 
PROG: combo
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main() {
  freopen("combo.in", "r", stdin);
  freopen("combo.out", "w", stdout);
  
  int n;
  int master[3];
  int john[3];
  int count = 0;

  cin >> n;

  for (int i = 0; i < 3; i++) {
      cin >> john[i];
  }

  for (int i = 0; i < 3; i++) {
      cin >> master[i];
  }

  for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
	  for (int k = 1; k <= n; k++) {
	      if (((abs(master[0] - i) <= 2 || abs(master[0]+n - i) <= 2 || abs(master[0] - (i+n)) <= 2) &&
		  (abs(master[1] - j) <= 2 || abs(master[1]+n - j) <= 2 || abs(master[1] - (n+j)) <= 2) &&
		  (abs(master[2] - k) <= 2 || abs(master[2]+n - k) <= 2 || abs(master[2] - (n+k)) <= 2)) ||

		 ((abs(john[0] - i) <= 2 || abs(john[0]+n - i) <= 2 || abs(john[0] - (i+n)) <= 2) &&
		  (abs(john[1] - j) <= 2 || abs(john[1]+n - j) <= 2 || abs(john[1] - (n+j)) <= 2) &&
		  (abs(john[2] - k) <= 2 || abs(john[2]+n - k) <= 2 || abs(john[2] - (n+k)) <= 2)))
		  count++;
	  }
      }
  }
  
  cout << count << endl;
  return 0;
}
