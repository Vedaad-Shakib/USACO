#include <iostream>
#include <stdio.h>
#include <stdint.h>

using namespace std;

char n[100001];
int  unMatched = 0;
int  reversed = 0;

int main() {
    freopen("clumsy.in", "r", stdin);
    freopen("clumsy.out", "w", stdout);

    cin >> n;

    for (int i = 0; n[i] != '\0'; i++) {
	if (n[i] == '(') {
	    unMatched++;
	} else {
	    unMatched--;
	}

	if (unMatched < 0) {
	    reversed++; // more ) than (, so reverse current paranthesis
	    unMatched += 2;
	}
    }

    if (unMatched > 0) {
	reversed += unMatched/2;
    }

    cout << reversed << endl;

    return 0;
}
