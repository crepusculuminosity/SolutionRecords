#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2010;
int a[maxn], b[maxn];
int n;
bool cmp(int x, int y) { return x > y; }
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  while (cin >> n && n) {
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
      cin >> b[i];
    sort(b + 1, b + 1 + n, cmp);
    int ans = 0;
    int l1 = 1, l2 = 1, r1 = n, r2 = n;
    while (l1 <= r1) {
      if (a[l1] > b[l2])
        ans += 200, ++l1, ++l2;
      else if (a[l1] < b[l2])
        ans -= 200, ++l2, --r1;
      else {
        if (a[r1] > b[r2])
          ans += 200, --r1, --r2;
        else {
          if (a[r1] < b[l2])//这里特判的原因是可能b[l2]=b[r2]
            ans -= 200;
          r1--, ++l2;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}