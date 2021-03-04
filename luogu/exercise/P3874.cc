#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3010;
int n;
int a[maxn], f[maxn][maxn];

int dfs(int l, int r) {
  if (f[l][r] != 0x3f3f3f3f)
    return f[l][r];
  if (l == r)
    return 0;
  if (r - l == 1) {
    if (a[r] == a[l])
      return 0;
    else
      return 1;
  }
  int &res = f[l][r];
  if (a[l] == a[r])
    res = min(res, dfs(l + 1, r - 1));
  else
    res = min(min(res, dfs(l + 1, r - 1) + 1),
              min(dfs(l + 1, r) + 1, dfs(l, r - 1) + 1));
  return res;
}

int main() {
  // freopen("data.in", "r", stdin);
  int n;
  scanf("%d", &n);
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  printf("%d", dfs(1, n));
  return 0;
}