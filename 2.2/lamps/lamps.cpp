/* 
ID: vedaad71 
PROG: lamps
LANG: C++11
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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX_N 1000

int n;
int c;
unordered_set<bitset<MAX_N> > first;
unordered_set<bitset<MAX_N> > second;
vector<int> on;
vector<int> off;
vector<bitset<MAX_N> > visited;
bitset<MAX_N> lamps;

void print(bitset<MAX_N> a) {
    for (int i = 0; i < n; i++) {
	cout << a[i];
    }
    cout << endl;
}

bitset<MAX_N> all(bitset<MAX_N> a) {
    bitset<MAX_N> b = a;
    for (int i = 0; i < n; i++) {
	b.flip(i);
    }

    return b;
}

bitset<MAX_N> even(bitset<MAX_N> a) {
    bitset<MAX_N> b = a;
    for (int i = 0; i < n; i += 2) {
	b.flip(i);
    }

    return b;
}

bitset<MAX_N> odd(bitset<MAX_N> a) {
    bitset<MAX_N> b = a;
    for (int i = 1; i < n; i += 2) {
	b.flip(i);
    }

    return b;
}

bitset<MAX_N> threes(bitset<MAX_N> a) {
    bitset<MAX_N> b = a;
    for (int i = 0; i < n; i += 3) {
	b.flip(i);
    }

    return b;
}

void cycle(int i) {
    if (i % 2 == 0) {
	second.clear();
	for (auto j = first.begin(); j != first.end(); j++) {
	    second.insert(all(*j));
	    second.insert(even(*j));
	    second.insert(odd(*j));
	    second.insert(threes(*j));
	}
    } else {
	first.clear();
	for (auto j = second.begin(); j != second.end(); j++) {
	    first.insert(all(*j));
	    first.insert(even(*j));
	    first.insert(odd(*j));
	    first.insert(threes(*j));
	}
    }
}

template< unsigned n > bool bitsetLess(bitset<n> const& x, bitset<n> const& y) {
    for (int i = 0; i < 1000; i++) {
        if (x[i] ^ y[i]) return y[i];
    }
    return false;
}

int main() {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);

    cin >> n;
    cin >> c;

    int tmp;
    cin >> tmp;
    while (tmp != -1) {
	on.push_back(tmp);
	cin >> tmp;
    }

    cin >> tmp;
    while (tmp != -1) {
	off.push_back(tmp);
	cin >> tmp;
    }

    lamps.flip(); // initially on

    first.insert(lamps);

    for (int i = 0; i < c; i++) {
	cycle(i);
	/*if (i % 2 == 0) {
	    for (auto j = second.begin(); j != second.end(); j++) {
		print((*j));
	    }
	} else {
	    for (auto j = first.begin(); j != first.end(); j++) {
		print((*j));
	    }
	}
	cout << endl;*/
    }

    // copy set to vector for easier iteration/sorting
    vector<bitset<MAX_N> > visited((c%2 == 0 ? first : second).begin(), (c%2 == 0 ? first : second).end());
    
    for (int i = visited.size()-1; i >= 0; i--) {
	bool flag = true;
	for (int j = 0; j < on.size(); j++)
	    if (visited[i][on[j]-1] == 0) flag = false;
	for (int j = 0; j < off.size(); j++) 
	    if (visited[i][off[j]-1] == 1) flag = false;

	if (!flag) visited.erase(visited.begin()+i);
    }

    sort(visited.begin(), visited.end(), bitsetLess<MAX_N>);
    
    for (int i = 0; i < visited.size(); i++) {
	print(visited[i]);
    }

    if (visited.size() == 0) cout << "IMPOSSIBLE" << endl;

    return 0;
}
