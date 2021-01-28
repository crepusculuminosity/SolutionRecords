#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int n, a, b;
struct line {
  int l, r;
  bool operator<(const line &x) const { return r < x.r; }
} q[MAXN];
int main() {
  freopen("data.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a, &b);
    q[i] = (line){a, b};
  }
  sort(q + 1, q + 1 + n);
  int ans = 0, k = 0;
  for (int i = 1; i <= n; i++) {
    if (q[i].l >= k) {
      k = q[i].r;
      ans++;
    }
  }
  printf("%d", ans);
  return 0;
}