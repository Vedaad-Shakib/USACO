/* 
ID: vedaad71 
PROG: castle
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <bitset>
#include <vector>
#include <functional>
#include <queue>
#include <map>

#define MAX_N 50

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
int m;
int grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int nRooms;
int maxRoom = 0;
int maxArea = 0;
int maxI;
int maxJ;
char loc;

void resetVisited() {
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    visited[i][j] = 0;
	}
    }
}

int dfs(int i, int j) {
    if (j < 0 || j >= m || i < 0 || i >= n) return 0;
    
    if (visited[i][j]) return 0;

    visited[i][j] = 1;
    int tmp = 1;
    if (!(grid[i][j]&1)) tmp += dfs(i, j-1);
    if (!((grid[i][j]>>1)&1)) tmp += dfs(i-1, j);
    if (!((grid[i][j]>>2)&1)) tmp += dfs(i, j+1);
    if (!((grid[i][j]>>3)&1)) tmp += dfs(i+1, j);

    return tmp;
}

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    cin >> grid[i][j];
	}
    }

    resetVisited();
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    int u = dfs(i, j);
	    if (u != 0) nRooms++;
	    if (u > maxRoom) {
		maxRoom = u;
	    }
	}
    }
    
    // gets max area when removing one wall
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    int tmp = grid[i][j]; // methodically remove each wall and dfs
	    if (j != 0 && tmp&1) { // west
		grid[i][j] -= 1;
		resetVisited();
		int u = dfs(i, j);
		if (u > maxArea || (u == maxArea && j < maxJ) || (u == maxArea && j == maxJ && i > maxI)) {		    		    
		    maxI = i;
		    maxJ = j;
		    loc = 'W';
		    maxArea = u;
		}
		grid[i][j] += 1;
	    }
	    if (i != 0 && (tmp>>1)&1) { // north
		grid[i][j] -= 2;
		resetVisited();
		int u = dfs(i, j);
		if (u > maxArea || (u == maxArea && j < maxJ) || (u == maxArea && j == maxJ && i > maxI)) {		    
		    maxI = i;
		    maxJ = j;
		    loc = 'N';
		    maxArea = u;
		}
		grid[i][j] += 2;
	    }
	    if (j != m-1 && (tmp>>2)&1) { // east
		grid[i][j] -= 4;
		resetVisited();
		int u = dfs(i, j);
		if (u > maxArea || (u == maxArea && j < maxJ) || (u == maxArea && j == maxJ && i > maxI)) {
		    maxI = i;
		    maxJ = j;
		    loc = 'E';
		    maxArea = u;
		}
		grid[i][j] += 4;
	    }
	    if (i != n-1 && (tmp>>3)&1) { // south
		grid[i][j] -= 8;
		resetVisited();
		int u = dfs(i, j);
		if (u > maxArea || (u == maxArea && j < maxJ) || (u == maxArea && j == maxJ && i > maxI)) {
		    maxI = i;
		    maxJ = j;
		    loc = 'S';
		    maxArea = u;
		}
		grid[i][j] += 8;
	    }
	}
    }

    cout << nRooms << endl;
    cout << maxRoom << endl;
    cout << maxArea << endl;
    cout << maxI+1 << " " << maxJ+1 << " " << loc << endl;

    return 0;
}
