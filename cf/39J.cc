#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
char a[maxn], b[maxn];
int res[maxn];
using ull = unsigned long long;
ull f[maxn], p[maxn], hb;

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  p[0] = 1;
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> (a + 1) >> (b + 1);
  int n = strlen(b + 1);
  int m = n + 1;
  for (int i = 1; i <= n; i++)
    hb = hb * 131 + b[i] - 'a' + 1;
  int cnt = 0;
  for (int i = 1; i <= n + 1; i++) {
    f[i] = f[i - 1] * 131 + a[i] - 'a' + 1;
    p[i] = p[i - 1] * 131;
  }
  // cout << hb << '\n';
  for (int i = 1; i <= m; i++) {
    ull tmp = f[i - 1] * p[m - i] + f[m] - f[i] * p[m - i];
    // cout << i << ' ' << tmp << '\n';
    if (tmp == hb)
      res[++cnt] = i;
  }
  cout << cnt << '\n';
  for (int i = 1; i <= cnt; i++)
    cout << res[i] << ' ';
  return 0;
}