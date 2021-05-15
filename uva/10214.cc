#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
typedef long long ll;
int num[maxn], prime[maxn], phi[maxn], cnt;
ll a, b;
void init() {
  phi[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (num[i] == 0)
      prime[++cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt && i * prime[j] < maxn; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = prime[j] * phi[i];
        break;
      } else
        phi[i * prime[j]] = (prime[j] - 1) * phi[i];
    }
  }
}

int main() {
  init();
  while (cin >> a >> b && (a + b)) {
    ll ans = 0;
    for (ll i = 1; i <= a; i++) {
      ans += b / i * phi[i];
      for (ll j = b / i * i + 1; j <= b; j++)
        if (__gcd(j, i) == 1)
          ++ans;
    }
    // ans += (b / i) * phi[i] + fun(b / i * i + 1);
    ans = ans * 4 + 4;
    double r = (double)ans / ((2 * b + 1) * (2 * a + 1) - 1);
    cout << fixed << setprecision(7) << r << '\n';
  }
  return 0;
}