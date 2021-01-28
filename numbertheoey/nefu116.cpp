#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  ll m, n;
  while (scanf("%ld%ld", &m, &n) == 2) {
    printf("%ld\n", m / gcd(m, n) * n);
  }
  return 0;
}