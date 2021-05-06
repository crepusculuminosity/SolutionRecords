#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 50000 + 10;
int n, k;
int fa[3 * maxn], rnk[3 * maxn];

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

int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  cin >> n >> k;
  // scanf("%d%d",&n,&k);
  int ans = 0;
  for (int i = 1; i <= 3 * n; i++)
    fa[i] = i, rnk[i] = 0;
  for (int i = 1; i <= k; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    // scanf("%d%d%d",&u,&v,&w);
    if (v < 1 || w < 1 || v > n || w > n)
      ++ans;
    else {
      if (u == 1) {
        if (find(v) == find(w + n) || find(v) == find(w + n * 2))
          ++ans;
        else
          merge(v, w), merge(v + n, w + n), merge(v + n * 2, w + n * 2);
      } else {
        if (find(v) == find(w) || find(v) == find(w + 2 * n))
          ++ans;
        else
          merge(v, w + n), merge(v + n, w + n * 2), merge(v + n * 2, w);
      }
    }
  }
  cout << ans;
  return 0;
}