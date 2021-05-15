#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e6 + 10;
ll num[maxn], prime[maxn], a[maxn], cnt, tot;
void init() {
  for (ll i = 2; i < maxn; i++) {
    if (!num[i]) {
      prime[++cnt] = i;
      for (ll j = i * i; j < (ll)1e12 + 10; j *= i)
        a[++tot] = j;
    }
    for (int j = 1; j <= cnt && i * prime[j] < maxn; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j] == 0)
        break;
    }
  }
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  sort(a + 1, a + 1 + tot);
  int _;
  cin >> _;
  while (_--) {
    ll l, r;
    cin >> l >> r;
    cout << upper_bound(a + 1, a + tot + 1, r) -
                lower_bound(a + 1, a + tot + 1, l)
         << '\n';
  }
  return 0;
}