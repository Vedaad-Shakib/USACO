/*                                                                                                                                                                                                       
ID: vedaad71                                                                                                                                                                                             
PROG: namenum
LANG: C++                                                                                                                                                                                             
*/
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int minimum(int a, int b) {
  if (a < b) { 
    return a;
  }
  return b;
}

int main() {
  ifstream fin("namenum.in");
  ofstream fout("namenum.out");
  string num;
  string letters[] = {"garbage because", "mapping starts at 2", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"}; //no Q or Z
  string name;
  ifstream dict("dict.txt");
  int index;
  bool printName;
  bool nameFound = false;
  
  fin >> num;
  for (int i = 0; i < 4617; i++) {
    printName = true;
    dict >> name;
    if (name.length() != num.length()) {
      continue;
    }
    for (int i = 0; i < minimum(num.length(), name.length()); i++) {
      istringstream buffer(num.substr(i, 1));
      buffer >> index;
      if (letters[index].find(name.at(i)) == string::npos) { //if letters[index] does not contain name[i]
	printName = false;
	break;
      }
    }
    if (printName) {
      fout << name << endl;
      nameFound = true;
    }
  }

  if (!nameFound) {
    fout << "NONE" << endl;
  }
  
  return 0;
}
