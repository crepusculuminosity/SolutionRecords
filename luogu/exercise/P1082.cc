#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, x, y;
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  ll d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

int main() {
  cin >> a >> b;
  exgcd(a, b, x, y);
  cout << (x % b + b) % b;
  return 0;
}