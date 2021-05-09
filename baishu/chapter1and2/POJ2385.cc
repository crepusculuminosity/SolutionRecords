#include <bits/stdc++.h>
#define N 1010
using namespace std;
int n, m, f[N][N], a[N], ans;
int dfs(int k, int s, int t) {
  if (t > n)
    return 0; // 时间已经全部过完
  if (f[t][k])
    return f[t][k];
  if (s == a[t])
    f[t][k] = dfs(k, a[t], t + 1) + 1;
  else {
    f[t][k] = max(f[t][k], dfs(k, s, t + 1));
    if (k < m)
      f[t][k] = max(f[t][k], dfs(k + 1, a[t], t + 1) + 1);
  }
  return f[t][k];
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  printf("%d", dfs(0, 1, 1));
  return 0;
}