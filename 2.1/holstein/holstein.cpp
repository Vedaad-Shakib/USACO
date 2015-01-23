/* 
ID: vedaad71 
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <bitset>

#define MAX_V 25
#define MAX_G 15

int v;
int g;
int vitamins[MAX_V+1];
int feed[MAX_G+1][MAX_V+1];
int result[MAX_V+1];
int tmp[MAX_V+1];
int answers[MAX_G+1];
int nAnswers = 10000;
int sumAnswers = 0;

using namespace std;

int nBitsSet(int a) {
    int counter = 0;
    for (int j = 0; j < g; j++)
	if (a >> j & 0x1) counter++;
    return counter;
}

int sumBits(int a) {
    int counter = 0;
    for (int j = 0; j < g; j++)
	if (a >> j & 0x1) counter += j;
    return counter;
}

int main() {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);

    cin >> v;
    for (int i = 0; i < v; i++) cin >> vitamins[i];
    cin >> g;
    for (int i = 0; i < g; i++)
	for (int j = 0; j < v; j++)
	    cin >> feed[i][j];

    // run through a brute-force powerset 
    for (int i = 1; i < pow(2, g); i++) {
	for (int j = 0; j < v; j++) {
	    tmp[j] = 0;
	}
	for (int j = 0; j < g; j++) {
	    if (i >> j & 0x1) {
		for (int k = 0; k < v; k++) {
		    tmp[k] += feed[j][k];
		}
	    }
	}
	bool flag = true;
	for (int j = 0; j < v; j++) if (tmp[j] < vitamins[j]) flag = false;

	if (flag) {
	    if (nBitsSet(i) < nAnswers || (nBitsSet(i) == nAnswers && sumBits(i) < sumAnswers)) {
		nAnswers = 0;
		for (int j = 0; j < g; j++) {
		    if (i >> j & 0x1) {
			answers[nAnswers] = j;
			nAnswers++;
		    }
		}
		sumAnswers = sumBits(i);
	    }
	}
    }
    
    cout << nAnswers << " ";
    for (int i = 0; i < nAnswers; i++) {
	cout << answers[i]+1;
	if (i != nAnswers-1) cout << " ";
    }
    cout << endl;

    return 0;
}
