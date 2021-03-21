#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll p;
ll ksm(ll a, ll b) {
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
  ll a, b;
  cin >> a >> b >> p;
  cout << ksm(a, b);
  return 0;
}