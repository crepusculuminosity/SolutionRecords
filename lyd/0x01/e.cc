#include <bits/stdc++.h>
using namespace std;
int n, m;
char str[5];
pair<string, int> a[100005];

int cal(int bit, int now) {
  for (int i = 1; i <= n; i++) {
    int x = a[i].second >> bit & 1;
    if (a[i].first == "AND")
      now &= x;
    else if (a[i].first == "OR")
      now |= x;
    else
      now ^= x;
  }
  return now;
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> str >> x;
    a[i] = make_pair(str, x);
  }

  int val = 0, ans = 0;
  for (int i = 29; i >= 0; i--) {
    int u = cal(i, 0), v = cal(i, 1);
    if (val + (1 << i) <= m && u < v)
      val += 1 << i, ans += v << i;
    else
      ans += u << i;
  }
  cout << ans;
  return 0;
}