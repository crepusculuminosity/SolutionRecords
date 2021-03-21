#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
double f[maxn][2];
double a[maxn];

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    f[i][0] = f[i - 1][0] + a[i];
  for (int i = n; i >= 1; i--)
    f[i][1] = f[i + 1][1] + a[i];
  for (int i = 1; i <= n; i++)
    f[i][0] = f[i][0] / i, f[n - i + 1][1] = f[n - i + 1][1] / i;
  double res = 0;
  for (int i = 1; i <= n; i++)
    res = max(res, max(f[i][0], f[n - i + 1][1]));
  cout << fixed << setprecision(9) << res;
  return 0;
}