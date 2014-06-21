/*
ID: vedaad71
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int find(bool ar[], int len, bool target) {
  for (int i = 0; i < len; i++) {
    if (ar[i] == target) {
      return i;
    }
  }
  return 7; //case #7 is no transformation
}

bool checkOne(int i, int j, int size, string initial[], string final[]) {
  return (initial[i][j] == final[j][size - 1 - i]);
}

bool checkTwo(int i, int j, int size, string initial[], string final[]) {
  return (initial[i][j] == final[size - 1 - i][size - 1 -  j]);
}

bool checkThree(int i, int j, int size, string initial[], string final[]) {
  return (initial[i][j] == final[size - 1 - j][i]);
}

bool checkFour(int i, int j, int size, string initial[], string final[]) {
  return (initial[i][j] == final[i][size - 1 - j]);
}

/*bool checkFive(int i, int j, int size, string initial[], string final[]) {
  return (initial[i][j] == final[size - 1 - j][size - 1 - i] ||
  initial[i][j] == final[size - 1 - i][j]            ||
  initial[i][j] == final[j][i]                         );
  }*/


bool checkSix(int i, int j, int size, string initial[], string final[]) {
  return (initial[i][j] == final[i][j]);
}

bool checkSeven(int i, int j, int size, string initial[], string final[]) {
  return (initial[i][j] == final[size - 1 - j][size - 1 - i]);
}

bool checkEight(int i, int j, int size, string initial[], string final[]) {
  return (initial[i][j] == final[size - 1 - i][j]);
}

bool checkNine(int i, int j, int size, string initial[], string final[]) {
  return (initial[i][j] == final[j][i]);
}

int main() {
  ifstream fin("transform.in");
  ofstream fout("transform.out");
  int size;
  fin >> size;
  string* initial = new string[size];
  string* final = new string[size];
  bool cases[10];
  fill_n(cases, 10, true);
  cases[0] = false; //we won't be using this one

  for (int i = 0; i < size; i++) {
    fin >> initial[i];
  }

  for (int i = 0; i < size; i++) {
    fin >> final[i];
  }

  for (int i = 0; i < size; i++) { //check for all the cases
    for (int j = 0; j < size; j++) {
      cases[1] = checkOne(i, j, size, initial, final) && cases[1];
      cases[2] = checkTwo(i, j, size, initial, final) && cases[2];
      cases[3] = checkThree(i, j, size, initial, final) && cases[3];
      cases[4] = checkFour(i, j, size, initial, final) && cases[4];

      cases[6] = checkSix(i, j, size, initial, final) && cases[6];
      cases[7] = checkSeven(i, j, size, initial, final) && cases[7];
      cases[8] = checkEight(i, j, size, initial, final) && cases[8];
      cases[9] = checkNine(i, j, size, initial, final) && cases[9];
    }

  }
  cases[5] = cases[7] || cases[8] || cases[9]; //either one of these has to be true for case 5 to be true
  cases[7], cases[8], cases[9] = false;
  fout << find(cases, 7, true) << endl;
  return 0;
}



