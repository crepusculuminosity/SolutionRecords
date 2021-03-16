#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1010;
int fa[maxn], rnk[maxn];

inline int find(int x) {
  if (fa[x] == x)
    return x;
  return fa[x] = find(fa[x]);
}

inline void merge(int x, int y) {
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
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    // set<int> s;
    int n, m;
    cin >> n >> m;
    int ans = n;
    for (int i = 1; i <= n; i++)
      fa[i] = i, rnk[i] = 0;
    for (int i = 1; i <= m; i++) {
      int a, b;
      cin >> a >> b;
      // merge(a,b);
      a = find(a), b = find(b);
      if (a != b) {
        merge(a, b);
        --ans;
      }
    }
    // for(int i=1;i<=n;i++) s.insert(find(i));
    cout << ans << '\n';
  }
  return 0;
}