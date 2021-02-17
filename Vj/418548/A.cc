#include <bits/stdc++.h>
using namespace std;
int n, r, d;
int main() {
  // freopen("data.in","r",stdin);
  int ans = 0;
  scanf("%d%d%d", &r, &d, &n);
  while (n--) {
    int c, x, y;
    scanf("%d%d%d", &x, &y, &c);
    int len = x * x + y * y;
    if ((c + r - d) * (c + r - d) <= len && (r - c) * (r - c) >= len &&
        c * 2 <= d)
      ans++;
  }
  printf("%d", ans);
}