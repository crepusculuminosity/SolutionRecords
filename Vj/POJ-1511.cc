#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
namespace FakeIO {
const int L = 1 << 16;
char buffer[L], *S, *T;
inline char _getChar() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, L, stdin);
    if (S == T)
      return EOF;
  }
  return *S++;
}
inline int _getInt() {
  char ch;
  int re = 0;
  for (ch = _getChar(); ch < '0' || ch > '9'; ch = _getChar())
    ;
  while (ch >= '0' && ch <= '9') {
    re = (re << 1) + (re << 3) + ch - 48, ch = _getChar();
  }
  return re;
}
} // namespace FakeIO
using FakeIO::_getInt;
const int maxn = 1e6+10;

typedef long long ll;
const int INF = 0x3f3f3f3f;
struct node {
  int to, w;
};
vector<node> G[2][maxn];
int d[maxn], ans;
int vis[maxn], n, m;
inline void addedge(int o, int u, int v, int w) {
  G[o][u].push_back(node{v, w});
}
struct Hnode {
  int d;
  int u;
  bool operator<(const Hnode &x) const { return d > x.d; }
};
void dijkstra(int o) {
  for (int i = 1; i <= n; i++)
    d[i] = INF, vis[i] = 0;
  d[1] = 0;
  priority_queue<Hnode> q;
  q.push(Hnode{0, 1});

  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (int i = 0; i < G[o][u].size(); i++) {
      node &e = G[o][u][i];
      if (d[e.to] > d[u] + e.w) {
        d[e.to] = d[u] + e.w;
        q.push(Hnode{d[e.to], e.to});
      }
    }
  }
  for (int i = 1; i <= n; i++)
    ans += d[i];
}
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int _ = _getInt();
  while (_--) {
    ans = 0;
    n = _getInt(), m = _getInt();
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++)
        G[i][j].clear();
    for (int i = 1; i <= m; i++) {
      int u = _getInt(), v = _getInt(), w = _getInt();
      addedge(0, u, v, w);
      addedge(1, v, u, w);
    }
    dijkstra(0), dijkstra(1);

    printf("%d\n", ans);
  }
  return 0;
}