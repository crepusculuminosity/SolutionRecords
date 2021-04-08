#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
using ll = long long;

int main() {
  int n;
  ll now = 0;
  ll a = 0, b = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    if (x - now > 0 && i > 1)
      a += (x - now);
    else if (x - now < 0)
      b += (now - x);
    now = x;
  }
  cout << max(a, b) << '\n' << abs(a - b) + 1;
  return 0;
}