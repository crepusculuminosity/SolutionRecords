#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, s1, v1, s2, v2;

ll work() {
  ll ans = -1;
  for (int a = 0; a <= n / max(s1, s2); a++) {
    int tmp = n / max(s1, s2);
    int b = (n - tmp * s1) / s2;
    ll res = (ll)a * v1 + (ll)b * v2;
    ans = max(ans, res);
  }
  return ans;
}

int main() {
  // freopen("data.in", "r", stdin);
  int _, kse = 1;
  cin >> _;
  while (_--) {
    cin >> n >> s1 >> v1 >> s2 >> v2;
    cout << "Case #" << kse++ << ": " << work() << endl;
  }
  return 0;
}