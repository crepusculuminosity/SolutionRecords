#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    ++mp[str];
  }

  int q;
  cin >> q;
  while (q--) {
    int ans = 0;
    string str;
    cin >> str;
    if (str.size() == 1)
      ans = mp[str];
    else {
      ans = mp[str];
      if (str[0] != str[1]) {
        swap(str[0], str[1]);
        ans += mp[str];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}