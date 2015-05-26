/* 
ID: vedaad71 
PROG: preface
LANG: C++
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

int i = 0;
int v = 0;
int x = 0;
int l = 0;
int c = 0;
int d = 0;
int m = 0;
int n;

void add(int value) {
  struct romandata_t { int value; char const* numeral; };
  static romandata_t const romandata[] =
     { 1000, "M",
        900, "CM",
        500, "D",
        400, "CD",
        100, "C",
         90, "XC",
         50, "L",
         40, "XL",
         10, "X",
          9, "IX",
          5, "V",
          4, "IV",
          1, "I",
          0, NULL }; // end marker
 
  for (romandata_t const* current = romandata; current->value > 0; ++current)
  {
    while (value >= current->value)
    {
      value  -= current->value;
      if (current->value == 1000)
	  m++;
      if (current->value == 900) {
	  m++;
	  c++;
      }
      if (current->value == 500)
	  d++;
      if (current->value == 400) {
	  c++;
	  d++;
      }
      if (current->value == 100) {
	  c++;
      }
      if (current->value == 90) {
	  c++;
	  x++;
      }
      if (current->value == 50) {
	  l++;
      }
      if (current->value == 40) {
	  l++;
	  x++;
      }
      if (current->value == 10) {
	  x++;
      }
      if (current->value == 9) {
	  x++;
	  i++;
      }
      if (current->value == 5)
	  v++;
      if (current->value == 4) {
	  v++;
	  i++;
      }
      if (current->value == 1)
	  i++;
    }
  }
}

int main() {
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);

    cin >> n;

    for (int j = 1; j <= n; j++) {
	add(j);
    }

    if (i != 0) cout << "I " << i << endl;
    if (v != 0) cout << "V " << v << endl;
    if (x != 0) cout << "X " << x << endl;
    if (l != 0) cout << "L " << l << endl;
    if (c != 0) cout << "C " << c << endl;
    if (d != 0) cout << "D " << d << endl;
    if (m != 0) cout << "M " << m << endl;
			

    return 0;
}
