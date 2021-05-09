#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
using ll = long long;

ll num[maxn], ans[maxn];

void init() {
  for (ll i = 2; i < maxn; i++) {
    if (!num[i]) {
      for (ll j = i * 2; j < maxn; j += i)
        num[j] = 1, ans[j] = 1;
      for (ll j = i; j < maxn; j *= i)
        ans[j] = i;
    }
  }
  // ans[2] = 1;
  for (ll i = 4; i < maxn; i++)
    ans[i] += ans[i - 1];
}

int main() {
  init();
  ll n;
  while (cin >> n)
    cout << ans[n] << '\n';
  return 0;
}