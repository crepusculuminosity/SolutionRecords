#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a;
  cin >> n >> m >> a;
  int x = m / a, y = n / a;
  if (n % a)
    ++x;
  if (m % a)
    ++y;
  long long ans = (long long)x * y;
  cout << ans;
  return 0;
}