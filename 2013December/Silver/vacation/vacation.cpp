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
typedef pair<long, long> ii;
typedef vector<long> vi;
typedef vector<ii> vii;

#define debug(a) cout << #a << ": " << (a) << endl;
#define MAX_N 200

ll	n;
ll	m;
ll	k;
ll	q;
ll	dist[MAX_N+1][MAX_N+1];
ll	sum    = 0;
ll	nValid = 0;

int main() {
    freopen("vacation.in", "r", stdin);
    freopen("vacation.out", "w", stdout);

    cin >> n >> m >> k >> q;

    // initialize dist matrix
    for (ll i = 0; i < n; i++) {
	for (ll j = 0; j < n; j++) {
	    dist[i][j] = 100000000000;
	}
    }

    // input adjacencies
    for (ll i = 0; i < m; i++) {
	ll u;
	ll v;
	ll d;
	cin >> u >> v >> d;
	dist[--u][--v] = d;
    }

    // set matrix diagonal
    for (ll i = 0; i < n; i++) {
	dist[i][i] = 0;
    }

    // calculate floyd-warshall
    for (ll l = 0; l < n; l++) {
	for (ll i = 0; i < n; i++) {
	    for (ll j = 0; j < n; j++) {
		if (dist[i][j] > dist[i][l] + dist[l][j])
		    dist[i][j] = dist[i][l] + dist[l][j];
	    }
	}
    }

    for (ll j = 0; j < q; j++) {
	ll a, b;
	ll minDist = 100000000000;
	cin >> a >> b;
	a--; b--;
	for (ll i = 0; i < k; i++) {
	    if (dist[a][i] != 100000000000 && dist[i][b] != 100000000000 && dist[a][i]+dist[i][b] < minDist) {
		minDist = dist[a][i] + dist[i][b];
	    }
	}
	if (minDist != 100000000000) {
	    sum += minDist;
	    nValid++;
	}
    }

    cout << nValid << endl;
    cout << sum << endl;
    
    return 0;
}
