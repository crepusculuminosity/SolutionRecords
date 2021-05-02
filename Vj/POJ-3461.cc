#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int maxp = 1e4 + 10;
const int maxs = 1e6 + 10;
char s[maxs], p[maxp];
ull f[maxs];
ull a[maxs];
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int _;
  a[0] = 1;
  scanf("%d", &_);
  while (_--) {
    scanf("%s%s", p + 1, s + 1);
    int n = strlen(s + 1), m = strlen(p + 1);
    ull h1 = 0;
    for (int i = 1; i <= m; i++)
      h1 = h1 * 131 + (p[i] - 'a' + 1);
    for (int i = 1; i <= n; i++)
      f[i] = f[i - 1] * 131 + (s[i] - 'a' + 1), a[i] = a[i - 1] * 131;
    int ans = 0;
    for (int i = 1; i + m - 1 <= n; i++)
      if (f[i + m - 1] - f[i - 1] * a[m] == h1)
        ++ans;
    printf("%d\n", ans);
  }
  return 0;
}