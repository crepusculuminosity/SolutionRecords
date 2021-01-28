#define RF freopen("data.in", "r", stdin);
#define WF freopen("data.out", "w", stdout);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 400;
constexpr int mod = 1e9;
char str[maxn];
ll dp[maxn][maxn];

ll solve(int l, int r) {
  if (l == r)
    return 1;
  if (l > r)
    return 0;
  if (str[l] != str[r])
    return 0;
  ll &ans = dp[l][r];
  if (ans >= 0)
    return ans;
  ans = 0;
  for (int k = l + 2; k <= r; k++)
    if (str[k] == str[l])
      ans = (ans % mod +
             ((solve(l + 1, k - 1) % mod) * (solve(k, r) % mod)) % mod) %
            mod;
  return ans;
}

int main() {
  // freopen("exploring.in","r",stdin);
  // freopen("exploring.out","w",stdout);
  while (~scanf("%s", str)) {
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve(0, strlen(str) - 1));
  }
  return 0;
}
