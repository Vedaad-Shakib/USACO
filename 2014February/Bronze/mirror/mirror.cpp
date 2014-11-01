#include <iostream>

using namespace std;

string mirrors[1000];
int n;
int m;
int numMirrors;
int maxRef = 0;
int mirrorId;

// r, l, u, d
char getDirection(int i, int j, char dir) {
  char mirror = mirrors[i][j];
  if (mirror == '/') {
    if (dir == 'r') {
      return 'u';
    }
    if (dir == 'l') {
      return 'd';
    }
    if (dir == 'd') {
      return 'l';
    }
    if (dir == 'u') {
      return 'r';
    }
  }

  if (mirror == '\\') {
    if (dir == 'r') {
      return 'd';
   }
    if (dir == 'l') {
      return 'u';
    }
    if (dir == 'd') {
      return 'r';
    }
    if (dir == 'u') {
      return 'l';
    }
  }
}

int cycleMirrors(int i, int j, char dir) {
  if (numMirrors > n * m) {
    return -1;
  } else if (i > n-1 || j > m-1 || i < 0 || j < 0) {
    return 0;
  } else {
    numMirrors++;
    char newDir = getDirection(i, j, dir);
    int dx = 0;
    int dy = 0;
    if (newDir == 'r') dx++;
    if (newDir == 'l') dx--;
    if (newDir == 'u') dy--;
    if (newDir == 'd') dy++;

    //cout << " dx: " << dx << " dy: " << dy << " i: " << i << " j: " << j <<" newI: " << i+dy << " newJ: " << j+dx << endl;
    return 1+cycleMirrors(i+dy, j+dx, newDir);
  }
}

int main() {
  freopen("mirror.in", "r", stdin);
  freopen("mirror.out", "w", stdout);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> mirrors[i];
  }

  for (int i = 0; i < m; i++) {
    numMirrors = 0;
    int tmp = cycleMirrors(0, i, 'd');
    if ((tmp > maxRef && maxRef != -1) || tmp == -1) maxRef = tmp;
    numMirrors = 0;
    tmp = cycleMirrors(n-1, i, 'u');
    if ((tmp > maxRef && maxRef != -1) || tmp == -1) maxRef = tmp;
  }

  for (int i = 0; i < n; i++) {
    numMirrors = 0;
    int tmp = cycleMirrors(i, 0, 'r');
    if ((tmp > maxRef && maxRef != -1) || tmp == -1) maxRef = tmp;
    numMirrors = 0;
    tmp = cycleMirrors(i, m-1, 'l');
    if ((tmp > maxRef && maxRef != -1) || tmp == -1) maxRef = tmp;
  }

  cout << maxRef << endl;

  return 0;
}
