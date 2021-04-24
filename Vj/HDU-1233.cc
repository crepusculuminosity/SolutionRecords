#include <bits/stdc++.h>
using namespace std;
struct edge {
  int from, to, w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[5050];
int n;
int fa[110], rnk[100];

int find(int x) {
  if (fa[x] == x)
    return x;
  return fa[x] = find(fa[x]);
}

bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return 0;
  if (rnk[x] < rnk[y])
    fa[x] = y;
  else {
    fa[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
  return 1;
}
int kruskal() {
  sort(es + 1, es + 1 + n * (n - 1) / 2);
  for (int i = 1; i <= n; i++)
    fa[i] = i, rnk[i] = 0;
  int res = 0;
  for (int i = 1; i <= n * (n - 1) / 2; i++) {
    if (merge(es[i].from, es[i].to))
      res +=es[i].w;
    // if(++now==n-1) break;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  //freopen("data.in", "r", stdin);
  while (cin >> n && n) {
    for (int i = 1; i <= n * (n - 1) / 2; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      es[i] = edge{u, v, w};
    }
    cout << kruskal() << '\n';
  }
  return 0;
}