#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 10;
constexpr int INF = -0x3f3f3f3f;
int n, m;
struct node {
  int to, w;
};
vector<node> G[maxn];
inline void addedge(int u, int v, int w) { G[u].push_back(node{v, w}); }
int d[maxn], vis[maxn], num[maxn];

bool SPFA(int s) {
  // memset(d, 0x3f, sizeof(d));
  for (int i = 1; i <= n; i++)
    d[i] = INF;
  d[s] = 0;
  vis[s] = 1;
  num[s]++;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = 0; i < G[u].size(); i++) {
      node &e = G[u][i];
      if (d[e.to] < d[u] + e.w) {
        d[e.to] = d[u] + e.w;
        if (!vis[e.to]) {
          q.push(e.to);
          vis[e.to] = 1;
          ++num[e.to];
          if (num[e.to] == n + 1)
            return 0;
        }
      }
    }
  }
  return 1;
}
int main() {

  // freopen("candy5.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int op, a, b;
    cin >> op >> a >> b;
    if (op == 1)
      addedge(a, b, 0), addedge(b, a, 0);
    else if (op == 2) {
      if (a == b) {
        puts("-1");
        return 0;
      }
      addedge(a, b, 1);
    } else if (op == 3)
      addedge(b, a, 0);
    else if (op == 4) {
      if (a == b) {
        puts("-1");
        return 0;
      }
      addedge(b, a, 1);
    }

    else
      addedge(a, b, 0);
  }
  for (int i = 1; i <= n; i++)
    addedge(0, i, 1);
  long long ans = 0;
  if (SPFA(0))
    for (int i = 1; i <= n; i++)
      ans += d[i];
  else
    ans = -1;
  cout << ans;
  return 0;
}