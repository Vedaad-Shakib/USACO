/*
ID: vedaad71
PROG: gift1
LANG: C++      
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
  
  ifstream fin("gift1.in");
  ofstream fout("gift1.out");

  map<string, int> theNames;
  int nNames;
  string name;
  int money;
  int nRecipients;
  
  fin >> nNames;
  
  vector<string> names(nNames);
  
  for (int i = 0; i < nNames; i++) {
    fin >> name;
    theNames.insert(make_pair(name, 0));
    names[i] = name;
  }
  
  for (int i = 0; i < nNames; i++) {
    fin >> name;
    fin >> money >> nRecipients;
    if (money == 0 || nRecipients == 0) {
      continue;
    }
    theNames[name] -= money;
    theNames[name] += money%nRecipients;
    money -= money % nRecipients;
    for (int j = 0; j < nRecipients; j++) {
      fin >> name;
      theNames[name] += money/nRecipients;
    }
    
  }
  /*for (auto &itr : theNames) {
    fout << itr.first << " " << itr.second << endl;
    }*/
  
  for (int i = 0; i < names.size(); i++) {
    fout << names.at(i) << " " << theNames[names.at(i)] << endl;
  }
  
  return 0;

}

