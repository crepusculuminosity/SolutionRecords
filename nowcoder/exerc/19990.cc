#include <bits/stdc++.h>
using namespace std;
int ans, n, b, m;
int c[60];
bool vis[60][1010];
void dfs(int i, int x) {
  if (x < 0 || x > m)
    return;
  if (vis[i][x])
    return;
  vis[i][x] = 1;
  if (i == n) {
    ans = max(ans, x);
    return;
  }
  dfs(i + 1, x + c[i + 1]);
  dfs(i + 1, x - c[i + 1]);
}

int main() {
  ans = -1;
  cin >> n >> b >> m;
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  dfs(0, b);
  cout << ans;
  return 0;
}