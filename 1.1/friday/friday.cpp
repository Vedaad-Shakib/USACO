/*
ID: vedaad71
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
  ifstream fin("friday.in");
  ofstream fout("friday.out");
  int years, month[12] = {31,28,31,30,31,30,31,31,30,31,30,31}, last, days[7], left = 0;

  for (int i = 0; i < 7; i++) {
    days[i] = 0;
  }

  fin >> years;

  last = 1900 + years;

  for (int i = 1900; i < last; i++) {
    if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
      month[1] = 29;
    }

    for (int j = 0; j < 12; j++) {
      days[(left + 13) % 7]++;
      left = month[j] - 13 + (left + 13) % 7;
    }

    month[1] = 28;
  }

  fout << days[6] << " " << days[0] << " " << days[1] << " " << days[2] << " " << days[3] << " " << days[4] << " " << days[5] << "\n";

  return 0;
}
