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

int main() {
  exgcd(-21, -225, d, x, y);
  printf("%lld %lld %lld", d, x, y);
  return 0;
}