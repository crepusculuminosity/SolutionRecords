#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    ll n, ans = -1;
    cin >> n;
    if (n % 3 == 0)
      ans = (n / 3) * (n / 3) * (n / 3);
    else if (n % 4 == 0)
      ans = (n / 4) * (n / 4) * (n / 4) * 2;
    cout << ans << '\n';
  }
  return 0;
}