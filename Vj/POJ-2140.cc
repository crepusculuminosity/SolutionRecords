#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll n;
int ans;

int main() {
  ll n, m;
  cin >> n;
  // while (cin >> n) {
  // ans = 0;
  m = 2 * n;
  for (ll i = 1; i * i <= m; i++) {
    if (m % i == 0 && (m / i - i) & 1)
      ++ans;
  }
  cout << ans;
  // }

  return 0;
}