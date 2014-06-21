/*
ID: vedaad71
PROG: ride
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
  string teamName;
  int teamNameValue = 1;
  string cometName;
  int cometNameValue = 1;
  string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
  ifstream fin("ride.in");
  ofstream fout("ride.out");

  getline(fin, teamName);
  getline(fin, cometName);
  
  for (int i = 0; i < teamName.length(); i++) {
    teamNameValue *= (letters.find(teamName[i]) + 1);
  }
  
  for (int i = 0; i < cometName.length(); i++) {
    cometNameValue *= (letters.find(cometName[i]) + 1);
  }
  
  if (cometNameValue%47 == teamNameValue%47) {
    fout << "GO" << endl;
  } else {
    fout << "STAY" << endl;
  }
  
  return 0;
	
}






