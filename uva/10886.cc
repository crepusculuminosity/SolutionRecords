#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e7 + 10;
long double a[maxn];
unsigned long long seed;

long double gen() {
  static const long double Z = (long double)1.0 / (1LL << 32);
  seed >>= 16;
  seed &= (1ULL << 32) - 1;
  seed *= seed;
  return seed * Z;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int _, kse = 1;
  scanf("%d", &_);
  while (_--) {
    int n;
    // cin >> n >> seed;
    scanf("%d%llu", &n, &seed);
    long double sum = 0.0, ans = 0.0;
    for (int i = 1; i <= n; i++) {
      a[i] = gen();
      sum += a[i];
    }
    sum /= n;
    for (int i = 1; i <= n; i++)
      ans += (a[i] - sum) * (a[i] - sum);
    printf("Case #%d: %.5Lf\n", kse++, (long double)sqrt(ans / n));
  }
  return 0;
}