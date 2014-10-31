#include <iostream>
#include <algorithm>

using namespace std;

string paint[100];
bool visited[100][100];
int n;

void visit(int i, int j) {
  visited[i][j] = true;
  if (i > 0 && !visited[i-1][j] && paint[i][j] == paint[i-1][j]) visit(i-1, j);
  if (i < n-1 && !visited[i+1][j] && paint[i][j] == paint[i+1][j]) visit(i+1, j);
  if (j > 0 && !visited[i][j-1] && paint[i][j] == paint[i][j-1]) visit(i, j-1);
  if (j < n-1 && !visited[i][j+1] && paint[i][j] == paint[i][j+1]) visit(i, j+1);
}

int main() {
  freopen("cowart.in", "r", stdin);
  freopen("cowart.out", "w", stdout);

  int count = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> paint[i];
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
	visit(i, j);
	count++;
      }
    }
  }

  cout << count << " ";
  count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      visited[i][j] = false;
    }
  }

  for (int i = 0; i < n; i++) {
    replace(paint[i].begin(), paint[i].end(), 'R', 'G');
  }

  for  (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
	visit(i, j);
	count++;
      }
    }
  }

  cout << count << endl;
  return 0;
}
