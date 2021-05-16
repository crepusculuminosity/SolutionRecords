#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5010;
int a[maxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  //freopen("data.in","r",stdin);
  //freopen("data.out","w",stdout);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    bool f = 0;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n - 2; i++) {
      int x = a[i];
      for (int j = i + 2; j <= n; j++)
        if (a[j] == x) {
          f = 1;
          break;
        }
      if (f)
        break;
    }
    if(f) puts("YES");
    else puts("NO");
  }
  return 0;
}