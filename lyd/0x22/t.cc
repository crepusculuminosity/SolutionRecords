#include <bits/stdc++.h>
using namespace std;
int w, n, c[20], cab[20], ans;

void dfs(int now, int cnt) {
  if (cnt >= ans)
    return;
  if (now == n + 1) {
    ans = min(ans, cnt);
    return;
  }
  for (int i = 1; i <= cnt; i++) {
    if (cab[i] + c[now] <= w) {
      cab[i] += c[now];
      dfs(now + 1, cnt);
      cab[i] -= c[now];
    }
  }
  cab[cnt + 1] = c[now];
  dfs(now + 1, cnt + 1);
  cab[cnt + 1] = 0;
}
bool cmp(int x, int y) { return x > y; }
int main() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  sort(c + 1, c + 1 + n, cmp);
  ans = n;
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}