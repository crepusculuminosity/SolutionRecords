#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, p;

ll ksc(ll a, ll b) {
  ll ans = 0;
  while (b) {
    if (b & 1)
      ans = (ans + a) % p;
    a = (a + a) % p;
    b >>= 1;
  }
  return ans;
}

int main() {
  cin >> a >> b >> p;
  cout << ksc(a, b);
  return 0;
}