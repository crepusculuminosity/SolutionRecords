#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 10;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll d[maxn];
int n, m;
bool vis[maxn];
template <typename T> inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48, ch = getchar();
  }
  x *= f;
}
struct node {
  int to, cst;
};
vector<node> G[2][maxn];
struct Hnode {
  ll d, u;
  bool operator<(const Hnode &x) const { return d > x.d; }
};

void dijkstra(int o) {
  priority_queue<Hnode> q;
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
    d[i] = INF;
  }
  vis[1] = 0, d[1] = 0;
  q.push(Hnode{0, 1});

  while (!q.empty()) {
    Hnode x = q.top();
    q.pop();
    int u = x.u;
    if (vis[u])
      continue;
    vis[u] = 1;
    for (int i = 0; i < G[o][u].size(); i++) {
      node e = G[o][u][i];
      if (d[e.to] > d[u] + e.cst) {
        d[e.to] = d[u] + e.cst;
        q.push(Hnode{d[e.to], e.to});
      }
    }
  }
}

int main() {
  //freopen("data.in","r",stdin);
  read(n), read(m);
  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    read(a), read(b), read(c);
    G[0][a].push_back(node{b, c});
    G[1][b].push_back(node{a, c});
  }
  dijkstra(0);
  for (int i = 1; i <= n; i++)
    ans += d[i];
  dijkstra(1);
  for (int i = 1; i <= n; i++)
    ans += d[i];
  printf("%lld",ans);

  return 0;
}