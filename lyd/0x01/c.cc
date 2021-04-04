#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a, b, p;

ll qsc(ll a, ll b) {
  ll res = 0;
  while (b) {
    if (b & 1)
      res = (res + a) % p;
    a = (a + a) % p;
    b >>= 1;
  }
  return res % p;
}

int main() {
  cin >> a >> b >> p;
  cout << qsc(a, b);
  return 0;
}