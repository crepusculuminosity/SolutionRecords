#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll x, k, d;

ll res(ll n) { return abs(x - k * d + 2 * n * d); }
int main() {
  cin >> x >> k >> d;
  double m = 1.0 * k / 2.0 - 1.0 * x / 2.0 / d;
  ll n = floor(m);
  // cout<<n;
  if (n < 0)
    n = 0;
  cout << min(res(n), res(n + 1)) << endl;
  return 0;
}