#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll m, n;
  while (cin >> n >> m && n) {
    if (n > m)
      swap(m, n);
    cout << m * n * (m + n - 2) + 2 * n * (n - 1) * (3 * m - n - 1) / 3 << endl;
  }
  return 0;
}