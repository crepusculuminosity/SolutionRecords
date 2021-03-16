#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e4 + 10;
vector<int> G[maxn];
int a[maxn], f[maxn];

int dfs(int x) {
  if (f[x])
    return f[x];
  for (int i = 0; i < G[x].size(); i++)
    f[x] = max(f[x], dfs(G[x][i]));
  f[x] += a[x];
  return f[x];
}
int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x >> a[i];
    int y;
    while (cin >> y && y)
      G[y].push_back(x);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = max(ans, dfs(i));
  cout << ans;
  return 0;
}