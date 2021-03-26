#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e7;

// a ^ b
ll ksm(ll a, ll b, ll mod) {
  ll ans = 1, base = a;
  while (b) {
    if (b & 1)
      ans = (ans * base) % mod;
    base = (base * base) % mod;
    b >>= 1;
  }
  return ans;
}

// a * b
ll ksc(ll a, ll b, ll mod) {
  ll ans = 0;
  while (b) {
    if (b & 1)
      ans = (ans + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return ans;
}

int main() {
  cout << "5 ^ 3 = " << ksm(43242424, 3131, mod) << endl;
  cout << "345352 * 11 = " << ksc(345352, 11, mod) << endl;
  system("pause");
  return 0;
}