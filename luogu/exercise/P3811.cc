#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 10;
int p, n;
ll a[maxn];

int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin >> n >> p;
  a[1] = 1;
  cout << a[1] << '\n';
  for (int i = 2; i <= n; i++) {
    a[i] = (p - p / i) * a[p % i] % p;
    cout << a[i] << '\n';
  }
  return 0;
}
