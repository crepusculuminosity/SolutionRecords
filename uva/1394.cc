#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 10005;
int n, k, m;
int a[maxn];

int main() {
  // freopen("data.in","r",stdin);
  while (scanf("%d%d%d", &n, &k, &m) == 3 && n) {
    a[1] = 0;
    for (int i = 2; i <= n; i++)
      a[i] = (a[i - 1] + k) % i;
    int ans = ((m - k + a[n]) % n + n) % n + 1;
    printf("%d\n", ans);
  }
  return 0;
}