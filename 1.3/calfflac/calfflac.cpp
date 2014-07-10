/*                                                                                                                                                                                                      
ID: vedaad71                                                                                                                                                                                              
PROG: calfflac                                                                                                                                                                                   
LANG: C++                                                                                                                                                                                               
*/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

struct indices {
  int indexBefore;
  int indexAfter;
};

// Finds the largest palindrome with index as the center
indices findPalindrome(string str, int index) {
  struct indices temp;
  int indexBefore = index-1;
  int indexAfter = index+1;

  //to account for even palindromes
  if (str[indexBefore] == str[index])
    indexAfter--;
  if (str[indexAfter] == str[index])
    indexBefore++;

  

  while (str[indexBefore] == str[indexAfter]) {
    indexBefore--;
    indexAfter++;
    if (indexBefore < 0 || indexAfter > str.length()-1)
      break;
  }

  indexBefore++; //if the check fails, the indices are still incremented
  indexAfter--;
  
  temp.indexBefore = indexBefore;
  temp.indexAfter = indexAfter;

  return temp;
}

//unformats a string and records what index maps to what
string unformatString(string str, map<int, int> &actualIndices) {
  string unformat = "";
  int j = 0;
  
  for (int i = 0; i < str.length(); i++) {
    if (isalpha(str[i])) {
      actualIndices[j++] = i;
      unformat += tolower(str[i]);
    }
  }

  return unformat;
}

int main() {
  /*ifstream fin("calfflac.in");
  ofstream fout("calfflac.out");
  string temp;
  string formattedString;
  string unformattedString;
  map<int, int> actualIndices;
  while (getline(fin, temp)) {
    formattedString += temp + '\n';
  }
  fout << unformatString(formattedString, actualIndices) << endl;
}*/
  ifstream fin("calfflac.in");
  ofstream fout("calfflac.out");

  string temp;
  string formattedString;
  string unformattedString;
  string longestPalindrome;
  int lenLongestPalindrome = 0;
  map<int, int> actualIndices;
  struct indices unformattedIndices;
  struct indices formattedIndices;

  while (getline(fin, temp)) {
    formattedString += temp + '\n';
  }

  unformattedString = unformatString(formattedString, actualIndices); //unformats the string and records what index maps to what

  for (int i = 0; i < unformattedString.length(); i++) {
    unformattedIndices = findPalindrome(unformattedString, i); //finds the longest palindrome starting from index i and then compares it to the longest stored palindrome
    formattedIndices.indexBefore = actualIndices[unformattedIndices.indexBefore]; formattedIndices.indexAfter = actualIndices[unformattedIndices.indexAfter];
    if (unformattedIndices.indexAfter - unformattedIndices.indexBefore + 1 > lenLongestPalindrome) {
      lenLongestPalindrome = unformattedIndices.indexAfter - unformattedIndices.indexBefore + 1; //problem statement requires the number of alphanumeric, palindromic characters
      longestPalindrome = formattedString.substr(formattedIndices.indexBefore, formattedIndices.indexAfter - formattedIndices.indexBefore + 1);
    }
  }
  fout << lenLongestPalindrome << endl;
  fout << longestPalindrome << endl;
  return 0;
  }
  
