#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 10;
int fa[maxn], rnk[maxn];

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
  // freopen("data.in","r",stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  while (m--) {
    int x, y;
    cin >> x >> y;
    merge(x, y);
  }
  int tot = n;
  for (int i = 1; i <= n; i++)
    if (fa[i] != i)
      --tot;
  cout << --tot;
  return 0;
}