#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20005;
int a[MAXN], b[MAXN];
int m, n;
int main() {
  // freopen("data.in","r",stdin);

  while (scanf("%d%d", &n, &m) == 2 && n && m) {
    for (int i = 1; i <= n; i++)
      scanf("%d", a + i);
    for (int i = 1; i <= m; i++)
      scanf("%d", b + i);
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    int ans = 0, cur = 1;
    for (int i = 1; i <= m; i++) {
      if (b[i] >= a[cur]) {
        ans += b[i];
        cur++;
      }
      if (cur == n + 1)
        break;
    }
    if (cur <= n)
      printf("Loowater is doomed!\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}