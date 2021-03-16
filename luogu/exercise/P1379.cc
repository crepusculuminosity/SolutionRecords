#include <bits/stdc++.h>
using namespace std;
constexpr int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int n;

int main() {
  cin >> n;
  queue<int> q;
  q.push(n);
  unordered_map<int, int> m;
  m[n] = 0;
  while (!q.empty()) {
    int u = q.front(), n = u;
    q.pop();
    int sx, sy;
    if (u == 123804765)
      break;
    int c[3][3];

    for (int i = 2; i >= 0; i--) {
      for (int j = 2; j >= 0; j--) {
        c[i][j] = n % 10, n /= 10;
        if (!c[i][j])
          sx = i, sy = j;
      }
    }

    for (int i = 0; i < 4; i++) {
      int xx = sx + dx[i], yy = sy + dy[i], nn = 0;
      if (xx < 0 || xx > 2 || yy < 0 || yy > 2)
        continue;
      swap(c[xx][yy], c[sx][sy]);

      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
          nn = nn * 10 + c[i][j];

      if (!m.count(nn)) {
        m[nn] = m[u] + 1;
        q.push(nn);
      }
      swap(c[xx][yy], c[sx][sy]);
    }
  }
  cout << m[123804765];
  return 0;
}