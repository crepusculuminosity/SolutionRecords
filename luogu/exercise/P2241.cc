#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  long long a = min(m, n);
  long long b = m + n - min(m, n);
  cout << a * (a + 1) * (3 * b + 1 - a) / 6 << " "
       << a * (a + 1) * b * (b + 1) / 4 - a * (a + 1) * (3 * b + 1 - a) / 6
       << endl;
  return 0;
}