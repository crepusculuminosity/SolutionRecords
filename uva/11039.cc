#define RF freopen("data.in", "r", stdin);
#define WF freopen("data.out", "w", stdout);
#include <bits/stdc++.h>
using namespace std;
int T, n, a[500010], last, ans;
inline bool cmp(int a, int b) { return abs(a) < abs(b); }

int main() {
  RF scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%d", a + i);
    sort(a + 1, a + 1 + n, cmp);
    last = a[1];
    ans = 1;
    for (int i = 2; i <= n; i++) {
      if (last < 0 && a[i] > 0)
        last = a[i], ans++;
      else if (last > 0 && a[i] < 0)
        last = a[i], ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}