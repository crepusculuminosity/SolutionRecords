#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[100000005];
int main() {
  scanf("%d%d", n, m);
  a[0] = 1;
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x], a[y + 1]++;
  }
  long long ans = 0;
  if (a[0] > 0)
    ans = 1;
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    if (a[i] > 0)
      ans++;
  }
  printf("%lld\n", ans);
  return 0;
}