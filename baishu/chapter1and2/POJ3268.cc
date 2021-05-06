#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, m, s;
int d[2][maxn], vis[maxn];

struct node {
  int to, w;
};
vector<node> G[2][maxn];
struct Hnode {
  int d, u;
  bool operator<(const Hnode &x) const { return d > x.d; }
};

void dijkstra(int o) {
  // memset(d,0x3f,sizeof(d));
  // for(int i=1;i<=n;i++) vis[o][i]=0;
  memset(vis, 0, sizeof(vis));
  priority_queue<Hnode> q;
  d[o][s] = 0;
  q.push(Hnode{0, s});
  while (!q.empty()) {
    int x = q.top().u;
    q.pop();
    if (vis[x])
      continue;
    vis[x] = 1;
    for (int i = 0; i < G[o][x].size(); i++) {
      node &e = G[o][x][i];
      if (d[o][e.to] > d[o][x] + e.w) {
        d[o][e.to] = d[o][x] + e.w;
        q.push(Hnode{d[o][e.to], e.to});
      }
    }
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  memset(d, 0x3f, sizeof(d));
  // cin >> n >> m >> s;
  scanf("%d%d%d", &n, &m, &s);
  while (m--) {
    int u, v, w;
    // cin >> u >> v >> w;
    scanf("%d%d%d", &u, &v, &w);
    G[0][u].push_back(node{v, w});
    G[1][v].push_back(node{u, w});
  }
  for (int i = 0; i < 2; i++)
    dijkstra(i);
  int sum = 0;
  for (int i = 1; i <= n; i++)
    sum = max(sum, d[0][i] + d[1][i]);
  // cout << sum;
  printf("%d", sum);
  return 0;
}