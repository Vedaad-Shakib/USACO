/* 
ID: vedaad71 
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

int aCap;
int bCap;
int cCap;

int a = 0;
int b = 0;
int c;

bool visited[21][21][21];
int answers[20];
int nAnswers = 0;

int milkTransferred;

void cycle(int a, int b, int c) {
    if (visited[a][b][c] == true) return; 
    else (visited[a][b][c] = true);

    if (a == 0) {
	answers[nAnswers] = c;
	nAnswers++;
    }

    milkTransferred = min(bCap-b, c);
    cycle(a, b+milkTransferred, c-milkTransferred);
    
    milkTransferred = min(bCap-b, a);
    cycle(a-milkTransferred, b+milkTransferred, c);
    
    milkTransferred = min(aCap-a, c);
    cycle(a+milkTransferred, b, c-milkTransferred);
    
    milkTransferred = min(aCap-a, b);
    cycle(a+milkTransferred, b-milkTransferred, c);
    
    milkTransferred = min(cCap-c, a);
    cycle(a-milkTransferred, b, c+milkTransferred);
    
    milkTransferred = min(cCap-c, b);
    cycle(a, b-milkTransferred, c+milkTransferred);
}

int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);

    cin >> aCap >> bCap >> cCap;

    c = cCap;
    
    for (int i = 0; i < c; i++) {
	answers[i] = 0;
    }

    for (int i = 0; i < 20; i++) {
	for (int j = 0; j < 20; j++) {
	    for (int k = 0; k < 20; k++) {
		visited[i][j][k] = false;
	    }
	}
    }

    
    milkTransferred = min(bCap, c);
    cycle(a, 0+milkTransferred, c-milkTransferred);
    milkTransferred = min(aCap, c);
    cycle(0+milkTransferred, b, c-milkTransferred);

    sort(answers, answers+nAnswers);

    for (int i = 0; i < nAnswers; i++) {
	cout << answers[i];
	if (i != nAnswers-1) cout << " ";
    }
    cout << endl;

    return 0;
}
