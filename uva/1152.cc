#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
const int maxn = 4050;
int a[maxn], b[maxn], c[maxn], d[maxn];

int main() {
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int _;
  // cin>>_;

  // while(_--) {
  int res = 0;
  // mp.clear();
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i] >> c[i] >> d[i];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      ++mp[a[i] + b[j]];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      res += mp[-c[i] - d[j]];
  }

  cout << res << '\n';
  // if(_) cout<<'\n';
  //}

  return 0;
}
