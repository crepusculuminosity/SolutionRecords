#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k, ans;

int main() {
  scanf("%lld %lld", &n, &k);
  ans = n * k;
  for (ll l = 1, r; l <= n; l = r + 1) {
    if (k / l != 0)
      r = min(n, k / (k / l));
    else
      r = n;
    ans -= (k / l) * (r - l + 1) * (l + r) / 2;
  }
  printf("%lld\n", ans);
  return 0;
}