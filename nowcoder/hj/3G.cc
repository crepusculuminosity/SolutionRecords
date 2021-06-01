#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
int a[maxn], fa[maxn];
int n, m;

int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (a[x] < a[y])
    fa[x] = y, a[x] = a[y];
  else
    fa[y] = x, a[y] = a[x];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    fa[i] = i, cin >> a[i];
  while (m--) {
    int u, v;
    cin >> u >> v;
    merge(u, v);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    ans += a[i];
  cout << ans;
  return 0;
}