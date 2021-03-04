#include <bits/stdc++.h>
using namespace std;
int n;
constexpr int maxn = 1e5 + 10;
double f[maxn];
double a[maxn];
int main() {
  freopen("data.in", "r", stdin);
  int n;
  for (int i = 1; i <= n; i++)
    scanf("%lf", a + i);
  double ans = 1;
  for (int i = 2; i <= n; i++)
    ans += (1 + 1.0 / a[i]);
  printf("%lf", ans);
  return 0;
}