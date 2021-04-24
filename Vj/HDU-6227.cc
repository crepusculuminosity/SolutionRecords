#include <bits/stdc++.h>
using namespace std;
int a[510];
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    // int ans = 0;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = a[2] - a[1] - 1;
    for (int i = 3; i <= n; i++) {
      ans = max(ans, a[i] - a[i - 1] - 1);
    }
    cout << ans << endl;
  }
  return 0;
}