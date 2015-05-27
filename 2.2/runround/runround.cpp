/* 
ID: vedaad71 
PROG: runround
LANG: C++11
*/
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <bitset>
#include <vector>
#include <functional>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;

bool isRunaround(int num) {
    string s = to_string(num);
    int visited[10];
    int actual[10];
    int arIndex = 0;
    int sIndex = 0;


    while (arIndex < s.length()+1) {
	visited[arIndex++] = sIndex;
	sIndex += s[sIndex]-'0';
	sIndex %= s.length();
    }

    if (visited[arIndex-1] != 0) // whether it wraps around to the first number
	return false;
    
    sort(visited, visited+s.length());

    // check for duplicate digits or 0 after list has been sorted
    for (int i = 0; i < s.length(); i++) {
	actual[i] = s[i]-'0';
    }

    sort(actual, actual+s.length());

    for (int i = 0; i < s.length()-1; i++)
	if (actual[i] == actual[i+1] || actual[i+1] == '0') return false;

    for (int i = 0; i < s.length(); i++) {
	if (visited[i] != i) return false; // make sure that every number has been accessed once
    }

    return true;
}

int main() {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);

    cin >> n;

    while (true) {
	n++;
	if (isRunaround(n)) {
	    cout << n << endl;
	    break;
	}
    }

    return 0;
}
