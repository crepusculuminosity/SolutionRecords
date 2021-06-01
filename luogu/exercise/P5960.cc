#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e3 + 10;
int n, m;
int d[maxn], vis[maxn], num[maxn];
struct node {
  int to, w;
};
vector<node> G[maxn];
void add(int u, int v, int w) { G[u].push_back(node{v, w}); }

bool SPFA() {
  memset(d, 0x3f, sizeof(d));
  d[0] = 0, vis[0] = 1, num[0] = 1;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
      node &e = G[u][i];
      if (d[e.to] > d[u] + e.w) {
        d[e.to] = d[u] + e.w;
        if (!vis[e.to]) {
          vis[e.to] = 1;
          num[e.to]++;
          q.push(e.to);
          if (num[e.to] == n + 1)
            return 0;
        }
      }
    }
  }
  return 1;
}
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    add(v, u, w);
  }
  for (int i = 1; i <= n; i++)
    add(0, i, 0);
  if (!SPFA())
    cout << "NO";
  else
    for (int i = 1; i <= n; i++)
      cout << d[i] + 114514 << ' ';
  return 0;
}