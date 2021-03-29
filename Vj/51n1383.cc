#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1e9 + 7;

ll dfs(ll x) {
  if (x == 1)
    return 1;
  return 1 + dfs(x >> 1);
}

int main() {
  ll res = 1;
  ll x;
  cin >> x;
  while (x) {
    ll y = x & -x;
    res = (res * dfs(y) % mod) % mod;
    x -= y;
  }
  cout << res;
  return 0;
}