#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
typedef long long ll;
ll a[MAXN];
map<ll, ll> m;

int main() {
  int n;
  ll c, ans = 0;
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    m[a[i]]++;
    a[i] -= c;
  }
  for (int i = 1; i <= n; i++)
    ans += m[a[i]];
  cout << ans << endl;
  return 0;
}