#include <bits/stdc++.h>
using namespace std;

int n, s, t, ans = 0x7ffffff;

int a[210], vis[210];

void dfs(int now, int step) {
  if (now == t)
    ans = min(ans, step);
  if (step > ans)
    return;
  vis[now] = 1;
  if (now + a[now] <= n && !vis[now + a[now]])
    dfs(now + a[now], step + 1);
  if (now - a[now] >= 1 && !vis[now - a[now]])
    dfs(now - a[now], step + 1);
  vis[now] = 0;
}

int main() {
  cin >> n >> s >> t;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  vis[s] = 1;
  dfs(s, 0);
  if (ans == 0x7ffffff)
    cout << -1;
  else
    cout << ans;
  return 0;
}