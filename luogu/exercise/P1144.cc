#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1000000 + 10;
int n, m;
int d[maxn], vis[maxn], num[maxn];
constexpr int mod = 100003;
vector<int> G[maxn];
struct Hnode {
  int d, u;
  bool operator<(const Hnode &x) const { return d > x.d; }
};

void dijkstra() {
  memset(d, 0x3f, sizeof(d));
  num[1] = 1;
  d[1] = 0;
  priority_queue<Hnode> q;
  q.push(Hnode{0, 1});
  while (!q.empty()) {
    int x = q.top().u;
    q.pop();
    if (vis[x])
      continue;
    vis[x] = 1;
    for (int i = 0; i < G[x].size(); i++) {
      int e = G[x][i];
      if (d[e] > d[x] + 1) {
        d[e] = d[x] + 1;
        num[e] = num[x];
        q.push(Hnode{d[e], e});
      } else if (d[e] == d[x] + 1)
        num[e] = (num[e] + num[x]) % mod;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // freopen("data.in", "r", stdin);
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dijkstra();
  for (int i = 1; i <= n; i++)
    cout << num[i] << '\n';
  return 0;
}