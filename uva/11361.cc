#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20][100][100];
ll mod;
ll p10[20];

ll dv[20];

ll dfs(int d, int m1, int m2) {
  if (d == 0)
    return m1 == 0 && m2 == 0;
  if (~dp[d][m1][m2])
    return dp[d][m1][m2];
  // dp[d][m1][m2]=0;
  ll &ans = dp[d][m1][m2];
  ans = 0;
  for (int i = 0; i < 10; ++i)
    ans += dfs(d - 1, (m1 - i % mod + mod) % mod,
               ((m2 - 1ll * p10[d - 1] * i % mod) + mod) % mod);
  return ans;
}

ll getws(ll val) {
  if (!val)
    return dv[0] = (dv[1] = 0) + 1;
  dv[0] = 0;
  while (val) {
    dv[++dv[0]] = val % 10;
    val /= 10;
  }
  return dv[0];
}

ll getans(ll val) {
  if (!val)
    return 1ll;
  ll res = 0;
  ++val;

  ll ws = getws(val);
  if (ws * 9 < mod)
    return 1ll;
  ll pre1 = 0, pre2 = 0;
  for (int i = ws; i >= 1; --i) {
    for (int j = 0; j < dv[i]; ++j) {
      if (j)
        pre1 += 1, pre2 %= mod;
      if (j)
        pre2 += p10[i - 1], pre2 %= mod;
      res += dfs(i - 1, (mod - pre1 + mod) % mod, (mod - pre2 + mod) % mod);
    }
    if (dv[i])
      ++pre1, pre2 += p10[i - 1];
  }
  return res;
}

int main() {
  // freopen("data.in", "r", stdin);
  p10[0] = 1;
  for (int i = 1; i <= 15; i++)
    p10[i] = 10ll * p10[i - 1];
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, -1, sizeof(dp));
    long long a, b;
    scanf("%lld%lld%lld", &a, &b, &mod);
    printf("%lld\n", getans(b) - getans(a - 1));
  }
  return 0;
}