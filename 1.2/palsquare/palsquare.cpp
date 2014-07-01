/*
ID: vedaad71
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string convertBase(int num, int base) {
  string digits = "0123456789ABCDEFGHIJK";

  if (num == 0) {
    return 0;
  }

  string result;

  while (num > 0) {
    ldiv_t temp = div((long)num, (long)base);
    result += digits[temp.rem];
    num = temp.quot;
  }
  reverse(result.begin(), result.end());

  return result;
}

bool isPalindrome(string num) {
  string revNum = "";
  for (int i = num.length()-1; i > -1; i--) {
    revNum += num[i];
  }

  if (revNum == num) {
    return true;
  }

  return false;
}

int main() {
  int base;
  ifstream fin("palsquare.in");
  ofstream fout("palsquare.out");
  fin >> base;

  for (int i = 1; i < 301; i++) {
    string number = convertBase(i, base);
    string sNumber = convertBase(i*i, base);
    if (isPalindrome(sNumber)) {
      fout << number << " " << sNumber << endl;
    }
  }

  return 0;
}


