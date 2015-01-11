/* 
ID: vedaad71 
PROG: crosswords
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX_N 50
#define MAX_M 50

char puzzle[MAX_N+1][MAX_M+1];
int n;
int m;
int numClues = 0;
int clues[(2*MAX_N*MAX_M)+1];

bool isHorizontal(int i, int j) {
    if (puzzle[i][j] == '.' && (j-1 < 0 || puzzle[i][j-1] == '#'))
	if (j+2 < m && puzzle[i][j+1] == '.' && puzzle[i][j+2] == '.')
	    return true;
    return false;
}

bool isVertical(int i, int j) {
    if (puzzle[i][j] == '.' && (i-1 < 0 || puzzle[i-1][j] == '#'))
	if (i+2 < n && puzzle[i+1][j] == '.' && puzzle[i+2][j] == '.')
	    return true;
    return false;
}

bool isClue(int i, int j) {
    return isHorizontal(i, j) || isVertical(i, j);
}

int main() {
    freopen("crosswords.in", "r", stdin);
    freopen("crosswords.out", "w", stdout);
  
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
	string tmp;
	cin >> tmp;
	for (int j = 0; j < m; j++) puzzle[i][j] = tmp[j];
    }

    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    if (isClue(i, j)) {
		clues[2*numClues+0] = i;
		clues[2*numClues+1] = j;
		numClues++;
	    }
	}
    }

    cout << numClues << endl;

    for (int i = 0; i < numClues; i++) cout << clues[2*i+0]+1 << " " << clues[2*i+1]+1 << endl;
    return 0;
}
