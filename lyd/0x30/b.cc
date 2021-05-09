#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
int num[maxn], p[100000];
typedef long long ll;
int cnt;
void init() {
  for (ll i = 2; i < maxn; i++) {
    if (num[i] == 0) {
      p[++cnt] = i;
      for (ll j = i * i; j < maxn; j += i)
        num[j] = 1;
    }
    // p[++cnt] = i;
    // for (int j = 1; j <= cnt && i * p[j] < maxn; j++) {
    // num[i * p[j]] = 1;
    // if (i % p[j])
    //  break;
    // }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  ll n;
  cin >> n;
  for (ll i = 1; i <= cnt && p[i] <= n; i++) {
    // int q = p[i];
    ll sum = 0;
    for (ll j = p[i]; j <= n; j *= p[i])
      sum += n / j;
    cout << p[i] << ' ' << sum << '\n';
  }
  return 0;
}