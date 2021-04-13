#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
string s;
unordered_map<string, int> m;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
void bfs() {
  queue<string> q;
  q.push("01234567");
  m["01234567"] = 0;
  while (!q.empty()) {
    string u = q.front();
    q.pop();
    // if (u == "01234567")
    // break;
    // if(!mu]) continue;
    char a[10][10];
    int sx, sy, xx, yy;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 4; j++) {
        a[i][j] = u[i * 4 + j];
        if (a[i][j] == '0')
          sx = i, sy = j;
      }
    for (int i = 0; i < 4; i++) {
      xx = sx + dx[i], yy = sy + dy[i];
      if (xx < 0 || xx > 1 || yy < 0 || yy > 3)
        continue;
      swap(a[xx][yy], a[sx][sy]);
      string nn;
      for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
          nn.push_back(a[i][j]);
      if (!m[nn]) {
        m[nn] = m[u] + 1;
        q.push(nn);
      }
      swap(a[xx][yy], a[sx][sy]);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  s = "01234567";
  bfs();
  //freopen("data.in", "r", stdin);
  while (cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5] >> s[6] >> s[7]) {
    // bfs();'
    if (s == "01234567")
      cout << "0\n";
    else
      cout << m[s] << '\n';
  }
  return 0;
}