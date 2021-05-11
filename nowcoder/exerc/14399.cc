#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 32000;
using ll = long long;
int num[maxn], prime[maxn], cnt;
int f;

void init() {
  for (ll i = 2; i < maxn; i++) {
    if (!num[i]) {
      prime[++cnt] = i;
      for (ll j = 1; j <= cnt && i * prime[j] < maxn; j++) {
        num[i * prime[j]] = 1;
        if (i % prime[j] == 0)
          break;
      }
    }
  }
}

map<int, int> solve(ll n) {
  // f = 0;
  map<int, int> res;
  for (ll i = 1; prime[i] * prime[i] <= n; i++) {
    while (n % prime[i] == 0)
      ++res[prime[i]], n /= prime[i], ++f;
  }
  if (n != 1)
    ++res[n], ++f;
  return res;
}

int main() {
//freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  init();
  cin >> _;
  while (_--) {
    f = 0;
    ll n;
    cin >> n;
    auto m = solve(n);
    if (f == 1)
      cout << "isprime\n";
    else
      cout << "noprime\n";
    for (auto it = m.begin(); it != m.end(); ++it) {
      if (it == --m.end())
        cout << it->first;
      else
        cout << it->first << ' ';
    }

    cout << "\n";
  }
  return 0;
}