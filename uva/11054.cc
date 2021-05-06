#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while (cin >> n && n) {
    ll ans = 0, a, lst = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a;
      ans += lst > 0 ? lst : -lst;
      lst += a;
    }
    cout << ans << '\n';
  }
  return 0;
}