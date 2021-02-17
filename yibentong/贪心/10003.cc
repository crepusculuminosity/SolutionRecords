#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1010;
struct work {
  int a, b, d;
  bool operator<(const work &x) const {
    if (d == x.d) {
      if (d <= 0)
        return a < x.a;
      else
        return b > x.b;
    }
    return d < x.d;
  }
} q[maxn];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> q[i].a;
  for (int i = 1; i <= n; i++)
    cin >> q[i].b;
  sort(q + 1, q + 1 + n);
  int ans = q[1].a, tmp = q[1].a + q[1].b;
  for (int i = 2; i <= n; i++) {
    tmp = max(ans + q[i].b, tmp) + q[i].b;
    ans += q[i].a;
  }
}