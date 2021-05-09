#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
int a[60][60];
int n, m, k;
bool vis[55][55][30][30][10];
struct State {
  int x, y, vx, vy, p, dis;
  // State(int x, int y, int vx, int vy, int p, int dis)
  //   : x(x), y(y), vx(vx), vy(vy), p(p), dis(dis) {}
  bool end() { return a[x][y] == k + 1 && vx == 0 && vy == 0 && p == k + 1; }
  bool valid() {
    return x >= 0 && y >= 0 && x < n && y < m && a[x][y] >= -1 && vx >= -10 &&
           vx <= 10 && vy <= 10 && vy >= -10;
  }
};
vector<State> v;

int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  cin >> n >> m >> k;
  int sx, sy;
  char str[60];
  for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = 0; j < m; j++) {
      if (str[j] == '.')
        a[i][j] = -1;
      else if (str[j] == '#')
        a[i][j] = -2;
      else
        a[i][j] = str[j] - '0';
      if (a[i][j] == 0) {
        vis[i][j][10][10][0] = 1;
        v.push_back({i, j, 0, 0, 0, 0});
      }
    }
  }

  for (int j = 0; j < v.size(); j++) {
    if (v[j].end()) {
      cout << v[j].dis;
      return 0;
    }
    for (int i = 0; i < 9; i++) {
      State S{v[j].x + v[j].vx + dx[i],
              v[j].y + v[j].vy + dy[i],
              v[j].vx + dx[i],
              v[j].vy + dy[i],
              v[j].p,
              v[j].dis + 1};
      if (S.valid()) {
        if (a[S.x][S.y] == v[j].p + 1)
          ++S.p;
        if (vis[S.x][S.y][S.vx + 10][S.vy + 10][S.p])
          continue;
        vis[S.x][S.y][S.vx + 10][S.vy + 10][S.p] = 1;
        v.push_back(S);
      }
    }
    cout << "impossible";
    return 0;
  }
}
