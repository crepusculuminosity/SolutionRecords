#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, ans, r, l;

int main() {
  while (cin >> n >> k) {
    //cin >> n >> k;
    ans = n * k;
    for (int l = 1; l <= n; l = r + 1) {
      if (k / l == 0)
        r = n;
      else
        r = min(k / (k / l), n);
      ans -= (k / l) * (l + r) * (r - l + 1) / 2;
    }
    cout << ans << '\n';
  }
  return 0;
}