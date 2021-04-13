#include <bits/stdc++.h>
using namespace std;
int c[20], a[20], n, w, ans;
bool cmp(int x, int y) { return x > y; }

void dfs(int u, int x) {
  if (x >= ans)
    return;
  if (u == n + 1) {
    ans = min(ans, x);
    return;
  }
  for (int i = 1; i <= x; i++) {
    if (c[u] + a[i] <= w) {
      a[i] += c[u];
      dfs(u + 1, x);
      a[i] -= c[u];
    }
  }
  a[x + 1] = c[u];
  dfs(u + 1, x + 1);
  a[x + 1] = 0;
}
int main() {
  //freopen("data.in","r",stdin);
  cin >> n >> w;
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  sort(c + 1, c + 1 + n, cmp);
  ans = n;
  dfs(1, 0);
  cout << ans;
  return 0;
}