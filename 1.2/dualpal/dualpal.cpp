/*
ID: vedaad71
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

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

int isPalindrome(string num) {
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
  ifstream fin("dualpal.in");
  ofstream fout("dualpal.out");
  int nNums;
  string num;
  fin >> nNums >> num;
  int numsFound = 0;
  int currentNum;
  istringstream buffer(num);
  buffer >> currentNum;
  currentNum += 1;
  while (numsFound < nNums) {
    int counter = 0;
    for (int j = 2; j < 11; j++) {
      if (isPalindrome(convertBase(currentNum, j))) {
	counter++;
	if (counter == 2) {
	  break;
	}
      }
    }
    if (counter == 2) {
      fout << currentNum << endl;
      numsFound++;
    }
    currentNum++;
  }

  return 0;
}


