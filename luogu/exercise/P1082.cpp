#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y, d;

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
  freopen("data.in", "r", stdin);
  ll a, b;
  cin >> a >> b;
  exgcd(a, b, d, x, y);
  cout << (x % b + b) % b << endl;
  return 0;
}
