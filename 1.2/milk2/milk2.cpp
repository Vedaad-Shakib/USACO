/*
ID: vedaad71
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;


struct times {
  int startTime, endTime;
};

bool compare(const times &a, const times &b) {
  return a.startTime < b.startTime;
}

int main() {
  int nFarmers;
  ifstream fin("milk2.in");
  ofstream fout("milk2.out");
  fin >> nFarmers;
  times* allTimes = new times[nFarmers];
  int longestMilk = 0;
  int longestIdle = 0;


  for (int i = 0; i < nFarmers; i++) {
    struct times temp;
    fin >> temp.startTime >> temp.endTime;
    allTimes[i] = temp;
  }
  sort(allTimes, allTimes+nFarmers, compare);
  int start = allTimes[0].startTime;
  int end = allTimes[0].endTime;

  for (int i = 0; i < nFarmers; i++) {

    if (allTimes[i].endTime >= end && allTimes[i].startTime <= end) {
      end = allTimes[i].endTime;
    }

    if (allTimes[i].startTime > end) {
      if (end - start > longestMilk) {
	longestMilk = end - start;
      }

      if (allTimes[i].startTime - end > longestIdle) {
	longestIdle = allTimes[i].startTime - end;
      }

      start = allTimes[i].startTime;
      end = allTimes[i].endTime;
    }
  }

  if (end - start > longestMilk) {
    longestMilk = end - start;
  }

  /*if (nFarmers == 1) {
    longestMilk = allTimes[0].endTime - allTimes[0].startTime;
    }*/


  fout << longestMilk << " " << longestIdle << endl;


  return 0;
}

