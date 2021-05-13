#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y, d; // d可能是负数，实际使用要取abs

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}

ll _exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  ll d = _exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
int main() {
  _exgcd(-21, -225,x, y);
  printf("%lld %lld %lld", d, x, y);
  return 0;
}