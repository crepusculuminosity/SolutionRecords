#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll m, n;

int main() {
  cin >> m >> n;
  cout << __gcd(2 * m, 2 * n) - __gcd(2 * m, n) - __gcd(2 * n, m) + __gcd(n, m);
  return 0;
}