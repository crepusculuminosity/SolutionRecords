#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
int a[maxn], m, n;

int main() {
  //freopen("data.in","r",stdin);
  //freopen("data.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a + 1, a + 1 + n);
    int h = 1, t = n;
    int cnt = 0;
    while (h <= t) {
      if(h==t) {
        ++cnt;
        break;
      }
      if (a[t] + a[h] <= m)
        ++h, --t;
      else
        --t;
      ++cnt;
    }
    cout<<cnt<<"\n";
    if(_) cout<<'\n';
  }
  return 0;
}