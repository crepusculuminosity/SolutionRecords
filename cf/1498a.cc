#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline ll fun(ll n) {
  ll res = 0;
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    ll n;
    cin >> n;
    if (n % 3 == 0)
      cout << n << '\n';
    else {
      for (int j = 0; j < 3; j++) {
        if (__gcd(n + j, fun(n + j)) > 1) {
          cout << n + j << '\n';
          break;
        }
      }
    }
  }
  return 0;
}