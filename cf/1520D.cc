#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 10;
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  //freopen("data.in", "r", stdin);
  int _;
  cin >> _;
  while (_--) {
    map<int, int> m;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x -= i;
      ans += m[x];
      m[x]++;
    }
    cout << ans << '\n';
  }
  return 0;
}