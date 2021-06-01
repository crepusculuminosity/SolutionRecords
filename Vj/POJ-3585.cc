#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200000 + 10;
int d[maxn], f[maxn];
int n;
struct node {
  int to;
  int w;
};
vector<node> G[maxn];
inline void add(int u, int v, int w) { G[u].push_back(node{v, w}); }
template <typename T> inline T _max(T a, T b) { return a > b ? a : b; }
template <typename T> inline T _min(T a, T b) { return a < b ? a : b; }
void init() {
  for (int i = 0; i <= n; i++)
    G[i].clear();
  memset(d, 0, sizeof(d));
  memset(f, 0, sizeof(f));
}
void dfs(int u, int fa) {
  for (int i = 0; i < G[u].size(); i++) {
    node &e = G[u][i];
    if (e.to != fa) {
      dfs(e.to, u);
      if (G[e.to].size() == 1)
        d[u] += e.w;
      else
        d[u] += _min(d[e.to], (int)e.w);
    }
  }
}
void DFS(int u, int fa) {
  // int k=G[u].size();
  for (int i = 0; i < G[u].size(); i++) {
    node &e = G[u][i];
    if (e.to != fa) {
      if (G[u].size() == 1)
        f[e.to] = d[e.to] + e.w;
      else
        f[e.to] = d[e.to] + _min(f[u] - _min(d[e.to], (int)e.w), (int)e.w);
      DFS(e.to, u);
    }
  }
}
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int _;
  scanf("%d", &_);
  while (_--) {
    scanf("%d", &n);
    init();
    for (int i = 1; i < n; i++) {
      int u, v;
      int w;
      scanf("%d%d%d", &u, &v, &w);
      add(u, v, w), add(v, u, w);
    }
    dfs(1, 0);
    f[1] = d[1];
    DFS(1, 0);
    int ans = -1;
    for (int i = 1; i <= n; i++)
      ans = _max(ans, f[i]);
    printf("%d\n", ans);
  }
  return 0;
}