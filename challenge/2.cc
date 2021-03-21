#include <bits/stdc++.h>
using namespace std;
long long n, m;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld %lld", &n, &m);
    if (m == n - 1)
      puts("0");
    else if (m == n)
      printf("%lld\n", n * n);
    else if (m < n - 1 || m > 2 * (n - 1))
      puts("-1");
    else {
      long long res = 0;
      long long p = m / (2 * (m - n));
      if (p > 1)
        res = p * m - (m - n) * p * p;
      p++;
      res = max(res, p * m - (m - n) * p * p);
      printf("%lld\n", res);
    }
  }
  return 0;
}
