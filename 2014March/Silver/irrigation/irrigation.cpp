#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define debug(a) cout << #a << ": " << (a) << endl;
#define MAX_N 2000

int n;
int c;
vector<vii> adj;
ii loc[MAX_N+1];
int cost;
vi taken;
priority_queue<ii> pq;

void process(int vtx) {
    taken[vtx] = 1;
    for (int i = 0; i < adj[vtx].size(); i++) {
	ii v = adj[vtx][i];
	if (!taken[v.first]) pq.push(make_pair(-v.second, -v.first));
    }
}

int main() {
    freopen("irrigation.in", "r", stdin);
    freopen("irrigation.out", "w", stdout);

    cin >> n >> c;

    adj.assign(n+1, vii());
    taken.assign(n+1, 0);

    for (int i = 0; i < n; i++) {
	cin >> loc[i].first >> loc[i].second;
	for (int j = 0; j < i; j++) {
	    if (i == j) continue;
	    cost = (loc[j].first-loc[i].first)*(loc[j].first-loc[i].first) + (loc[j].second-loc[i].second)*(loc[j].second-loc[i].second);
	    if (cost >= c) {
		adj[i].push_back(make_pair(j, cost));
		adj[j].push_back(make_pair(i, cost));
	    }
	}
    }

    for (int i = 0; i < n; i++) {
	if (adj[i].size() == 0) {
	    cout << -1 << endl;
	    return 0;
	}
    }

    /*for (int i = 0; i < n; i++) {
	cout << i << ": (" << loc[i].first << ", " << loc[i].second << endl;
	for (int j = 0; j < adj[i].size(); j++) {
	    cout << "        " << adj[i][j].first << ", " << adj[i][j].second << endl;
	}
	}*/

    process(0);
    cost = 0;
    while (!pq.empty()) {
	ii front = pq.top();
	pq.pop();
	int u = -front.second;
	int w = -front.first;
	if (!taken[u]) {
	    cost += w;
	    process(u);
	}
    }

    cout << cost << endl;

    return 0;
}
