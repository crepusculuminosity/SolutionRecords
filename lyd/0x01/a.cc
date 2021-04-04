#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll qsm(ll a, ll b, ll p) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res % p;
}

int main() {
  ll a, b, p;
  cin >> a >> b >> p;
  cout << qsm(a, b, p);
  return 0;
}