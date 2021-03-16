#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1510;
queue<int> q;
int G[maxn][maxn];
int n, m;
int dis[maxn];

void bfs() {
  memset(dis, -1, sizeof(dis));
  dis[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (G[u][i] && dis[i] < dis[u] + G[u][i]) {
        dis[i] = dis[u] + G[u][i];
        q.push(i);
      }
    }
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  int a, b, v;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> v;
    G[a][b] = max(G[a][b], v);
  }
  bfs();
  cout << dis[n];
  return 0;
}