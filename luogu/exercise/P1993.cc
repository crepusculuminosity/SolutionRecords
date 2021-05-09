#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}
constexpr int maxn = 5010;
int n, m;
struct node {
  int to, w;
};
vector<node> G[maxn];
int d[maxn], vis[maxn], num[maxn];

bool SPFA(int s) {
  memset(d, 0x3f, sizeof(d));
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
      if (d[e.to] > d[u] + e.w) {
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
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int op = read();
    if (op == 3) {
      int a = read(), b = read();
      G[a].push_back(node{b, 0});
      G[b].push_back(node{a, 0});
    } else if (op == 2) {
      int a = read(), b = read(), c = read();
      G[b].push_back(node{a, c});
    } else {
      int a = read(), b = read(), c = read();
      G[a].push_back(node{b, -c});
    }
  }
  for (int i = 1; i <= n; i++)
    G[n + 1].push_back(node{i, 0});
  if (SPFA(n + 1))
    puts("Yes");
  else
    puts("No");
  return 0;
}