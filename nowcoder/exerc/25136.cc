#include <bits/stdc++.h>
using namespace std;
int n;
struct tiao {
  int a, b;
  bool operator<(const tiao &x) const { return b < x.b; }
} q[32010];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> q[i].a >> x;
    q[i].b = q[i].a + x;
  }
  sort(q + 1, q + 1 + n);
  int ans = 0, tot = 0;
  for (int i = 1; i <= n; i++) {
    if (tot <= q[i].a) {
      ans++;
      tot = q[i].b;
    }
  }
  cout << ans;
  return 0;
}