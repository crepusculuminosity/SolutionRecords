#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string s;
int main() {
  // freopen("data.in", "r", stdin);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    int sx = 1, sy = 1;
    cin >> s;
    a[sx][sy] = 1;
    int j = 2;
    for (auto it = s.begin(); it != s.end(); it++) {
      if (*it == 's')
        sx += dx[0], sy += dy[0];
      if (*it == 'd')
        sx += dx[1], sy += dy[1];
      if (*it == 'w')
        sx += dx[2], sy += dy[2];
      if (*it == 'a')
        sx += dx[3], sy += dy[3];
      a[sx][sy] = j++;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}