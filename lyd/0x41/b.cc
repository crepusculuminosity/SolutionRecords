#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 30001;
int fa[maxn], rnk[maxn], d[maxn];

int find(int x) {
  if (x == fa[x])
    return x;
  int root = find(fa[x]);
  d[x] += d[fa[x]];
  return fa[x] = root;
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  fa[x] = y, d[x] = rnk[y];
  rnk[y] += rnk[x];
}

int main() {
  freopen("data.in","r",stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  for (int i = 1; i <= 30000; i++)
    fa[i] = i,rnk[i]=1;
  int _;
  cin >> _;
  while (_--) {
    int a, b;
    char op;
    cin >> op >> a >> b;
    if (op == 'M') {
      merge(a, b);
    } else {
      if (find(a) != find(b))
        cout << -1 << '\n';
      else cout << abs(d[a] - d[b]) - 1 << '\n';
    }
  }
  return 0;
}