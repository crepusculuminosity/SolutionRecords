#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
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
const int maxn = 1010;
struct node {
  int to, w;
};
vector<node> G[maxn];
inline void add(int u, int v, int w) { G[u].push_back(node{v, w}); }
int n, ML, MD;
int d[maxn], vis[maxn], num[maxn];
const int INF = 0x3f3f3f3f;

bool SPFA(int s) {
  memset(d, 0x3f, sizeof(d));
  memset(vis, 0, sizeof(vis));
  memset(num, 0, sizeof(num));
  d[s] = 0, vis[s] = 1, num[s] = 1;
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
          num[e.to]++;
          if (num[e.to] == n + 1)
            return 0;
        }
      }
    }
  }
  return 1;
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  n = read(), ML = read(), MD = read();
  for (int i = 1; i <= ML; i++) {
    int a = read(), b = read(), c = read();
    add(a, b, c);
  }
  for (int i = 1; i <= MD; i++) {
    int a = read(), b = read(), c = read();
    add(b, a, -c);
  }
  for (int i = 1; i < n; i++)
    add(i + 1, i, 0);
  for (int i = 1; i <= n; i++)
    add(0, i, 0);
  if (!SPFA(0))
    puts("-1");
  else {
    SPFA(1);
    if (d[n] == INF)
      puts("-2");
    else
      printf("%d", d[n]);
  }
  return 0;
}