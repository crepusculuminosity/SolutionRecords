#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
constexpr int INF = 0x7fffffff;
int d[maxn];
int n, m, s;
struct node {
  int to, w;
};
vector<node> G[maxn];
int vis[maxn];
inline int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x;
}
void SPFA() {
  // memset(d, 0x7f, sizeof(d));
  fill(d + 1, d + n + 1, INF);
  d[s] = 0;
  queue<int> q;
  q.push(s);
  // vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
      node &e = G[u][i];
      if (d[e.to] > d[u] + e.w) {
        d[e.to] = d[u] + e.w;
        if (!vis[e.to]) {
          q.push(e.to);
          vis[e.to] = 1;
        }
      }
    }
  }
}
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // int n, m, s;
  n=read(),m=read(),s=read();
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    //cin >> u >> v >> w;
    u=read(),v=read(),w=read();
    G[u].push_back(node{v, w});
  }
  SPFA();
  for (int i = 1; i <= n; i++)
    printf("%d ", d[i]);
  return 0;
}
