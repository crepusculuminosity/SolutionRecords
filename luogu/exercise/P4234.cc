#include <bits/stdc++.h>
#include <ios>
using namespace std;
int n, m;
constexpr int maxn=5e4+10;
constexpr int maxm=2e5+10;
int fa[maxn], rnk[maxn];
const int INF = 0x3f3f3f3f;
struct edge {
  int from, to, w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[maxm];

int find(int x) {
  if (x == fa[x])
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

int kruskal(int l) {
  for (int i = 1; i <= n; i++)
    fa[i] = i, rnk[i] = 0;
  int now = 0;
  for (int r = l; r <= m; r++) {
    if (merge(es[r].to, es[r].from)) {
      if (++now == n - 1)
        return es[r].w - es[l].w;
    }
  }
  return INF;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // freopen("data.in", "r", stdin);
  // freopen("data.out","w",stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    es[i] = edge{u, v, w};
  }
  sort(es + 1, es + 1 + m);
  int ans = 0x3f3f3f3f;
  for (int l = 1; l <= m; l++) 
    // cout<<kruskal(l)<<endl;
    ans = min(ans, kruskal(l));
  
  cout << ans;

  return 0;
}