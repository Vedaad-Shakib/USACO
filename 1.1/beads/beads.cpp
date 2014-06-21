/*
ID: vedaad71
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream> 

using namespace std;
char opposite(char bead) {
  if (bead == 'r') {
    return 'b';
  } else {
    return 'r';
  }
}
int findAfter(int index, string beads, char color) {
  //Finds the chain after and including a given index
  bool isWhite = false;
  if (color == 'w') {
    color = 'r';
    isWhite = true;

  }
  int chain = 0;
  int i = index;
  int stoppingPoint = (index-1<0) ? beads.length()-1: index-1;
  while (i != stoppingPoint && beads[i] != opposite(color)) {
    if (beads[i] == opposite(color)) {
      cout << "something is wrong" << endl;
    }

    chain += 1;
    i += 1;
    i %= beads.length();
  }
  if (isWhite) {
    chain = max(chain, findAfter(index, beads, 'b'));
  }
  return chain;
}

int findBefore(int index, string beads, char color) {
  //Finds the chain before and including a given index
  bool isWhite = false;
  if (color == 'w') {
    color = 'r';
    isWhite = true;
  }
  int chain = 0;
  int i = index;
  while (i != (index+1)%beads.length() && beads[i] != opposite(color)) {
    chain += 1;
    i -= 1;
    if (i < 0) {
      i = beads.length() - 1;
    }
  }

  if (isWhite) {
    chain = max(chain, findBefore(index, beads, 'b'));
  }

  return chain;
}



int main() {
  string beads;
  int max = 0;
  int nBeads;
  ifstream fin("beads.in");
  ofstream fout("beads.out");
  fin >> nBeads;
  fin >> beads;
  for (int i = 0; i < nBeads; i++) {
    char color = beads[i];
    char colorAfter = beads[(i+1)%nBeads];
    int chainBefore;
    int chainAfter;

    chainBefore = findBefore(i, beads, color);
    chainAfter = findAfter(((i+1)%nBeads), beads, colorAfter);
   
    if (max < chainBefore + chainAfter) {
      max = chainBefore + chainAfter;
    }

  }
  if (max > beads.length()) {
    max = beads.length();
  }
  fout << max << endl;
  return 0;
}






