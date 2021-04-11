#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  int v, k, c, l;
  bool operator<(const node &x) const { return v < x.v; }
} q[1010];
int s[1010], dp[1010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);

  int _, kse = 1;
  cin >> _;
  while (_--) {
    cin >> n;
    memset(s, 0, sizeof(s));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
      cin >> q[i].v >> q[i].k >> q[i].c >> q[i].l;
    sort(q + 1, q + 1 + n);
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + q[i].l;
      dp[i] = dp[i - 1] + q[i].k + q[i].c * q[i].l;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++)
        dp[i] = min(dp[i], dp[j] + (s[i] - s[j]) * q[i].c + q[i].k);
    }
    cout << "Case " << kse++ << ": " << dp[n] << '\n';
  }
  return 0;
}
