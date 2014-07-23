/*                                                                                                                                                                                                
ID: vedaad71                                                                                                                                                                                              
PROG: crypt1
LANG: C++                                                                                                                                                                                                
*/

#include <iostream>
#include <vector>
#include "math.h"
#include <fstream>

using namespace std;

bool contains(vector<int> array,  int num) {
  for (int i = 0; i < array.size(); i++) {
    if (array[i] == num) {
      return true;
    }
  }
  return false;
}

bool isValid(int num, vector<int> digits, int numDigits) {
  if (num > pow(10, numDigits) - 1) { //ex: numdigits = 3, pow(10, numdigits)-1 = 999
    return false;
  }

  while (num > 0) {
    if (!contains(digits, num%10)) {
      return false;
    }
    num /= 10;
  }

  return true;
}

int main() {
  ifstream fin("crypt1.in");
  ofstream fout("crypt1.out");
  int counter = 0;
  int a = 0;
  int b = 0;
  int numDigits;
  fin >> numDigits;
  vector<int> digits(numDigits);
  
  for (int i = 0; i < numDigits; i++) {
    fin >> digits[i];
  }
  
  for (int i = 0; i < numDigits; i++) {
    for (int j = 0; j < numDigits; j++) {
      for (int k = 0; k < numDigits; k++) {
	for (int l = 0; l < numDigits; l++) {
	  for (int m = 0; m < numDigits; m++) {
	    a = digits[i]*100 + digits[j]*10 + digits[k];
	    b = digits[l]*10 + digits[m];
	    if (isValid(a*digits[l], digits, 3) && isValid(a*digits[m], digits, 3) && isValid(a*b, digits, 4)) {
	      counter++;
	    }
	  }
	}
      }
    }
  }
  fout << counter << endl;
  
  return 0;
}
