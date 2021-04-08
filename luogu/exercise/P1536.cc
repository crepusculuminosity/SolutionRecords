#include <bits/stdc++.h>
using namespace std;

int fa[1010], rnk[1010];
int n, m;

int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return;
  if (rnk[x] < rnk[y])
    fa[x] = y;
  else {
    fa[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // freopen("data.in","r",stdin);
  while (cin >> n >> m && n) {
    for (int i = 1; i <= 1000; i++)
      fa[i] = i, rnk[i] = 0;
    int u, v;
    for (int i = 1; i <= m; i++) {
      cin >> u >> v;
      merge(u, v);
    }
    int tot = n;
    for (int i = 1; i <= n; i++)
      if (find(i) != i)
        --tot;
    cout << --tot << '\n';
  }
  return 0;
}