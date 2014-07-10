/*                                                                                                                                                                                                       
ID: vedaad71                                                                                                                                                                                             
PROG: barn1
LANG: C++                                                                                                                                                                                               
*/
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("barn1.in");
  ofstream fout("barn1.out");

  int numBoards;
  int numStalls;
  int numCows;
  fin >> numBoards >> numStalls >> numCows;
  int cows[numCows];
  int largestGaps[numBoards-1];
  int gap;
  int stallsBlocked = 0; 

  for (int i = 0; i < numBoards-1; i++) largestGaps[i]=0;

  for (int i = 0; i < numCows; i++)
    fin >> cows[i];
  sort(cows, cows+numCows);
  
  stallsBlocked = cows[numCows-1] - cows[0] + 1;

  // find the largest gap between cows, so the max number of stalls can be ignored.
  for (int i = 0; i < numCows-1; i++) {
    gap = cows[i+1] - cows[i] - 1; //number of stalls between cows
    if (gap > largestGaps[0]) {
      largestGaps[0] = gap;
      sort(largestGaps, largestGaps+numBoards-1);
    }
  }
  
  for (int i = 0; i < numBoards-1; i++) {
    stallsBlocked -= largestGaps[i];
  }
  
  fout << stallsBlocked << endl;
  return 0;
}
