#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
char a[maxn], b[maxn];
using ull = unsigned long long;
using ll = long long;
ull p[maxn], f[maxn];
ull h;
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  p[0] = 1;
  cin >> (a + 1) >> (b + 1);
  int n = strlen(a + 1), m = strlen(b + 1);
  for (int i = 1; i <= m; i++)
    h = h * 131 + a[i] - 'A' + 1;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] * 131 + a[i] - 'A' + 1;
    p[i] = p[i - 1] * 131;
  }
  int ans = 0;
  for (int i = m; i <= n; i++)
    if (f[i] - f[i - m] * p[i - m + 1] == h)
      ++ans;
  cout << ans;
  return 0;
}