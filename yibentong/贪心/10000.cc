#include <bits/stdc++.h>
using namespace std;

int n;
struct act {
  int s, f;
  bool operator<(const act &x) { return f < x.f; }
} q[1010];

int main() {
  // freopen("data.in", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> q[i].s >> q[i].f;
  sort(q + 1, q + 1 + n);
  int now = 1, ans = 1;
  for (int i = 2; i <= n; i++)
    if (q[i].s >= q[now].f) {
      ans++;
      now = i;
    }
  cout << ans;
  return 0;
}