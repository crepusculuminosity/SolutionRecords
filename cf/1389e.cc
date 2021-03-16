#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  // freopen("data.in", "r", stdin);
  int _;
  cin >> _; //注意求和最后一项在分块中的位置
  while (_--) {
    // ll ans=0;
    ll m, d, w;
    cin >> m >> d >> w;
    m = min(m, d);
    w /= __gcd(d - 1, w);
    ll ks = (m - 1) / w;
    ll ans = w * (ks - 1) * ks / 2 + ks * (m - ks * w);
    cout << ans << endl;
  }
  return 0;
}