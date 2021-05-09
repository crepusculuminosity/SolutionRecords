#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 310;
int a[maxn];
int p[1000010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  /// freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    // bool f;
    int m = 1;
    do {
      bool f = 1;
      memset(p, 0, sizeof p);
      for (int i = 1; i <= n; i++) {
        if (p[a[i] % m]) {
          f = 0;
          break;
        }
        p[a[i] % m] = 1;
      }
      if (f)
        break;
    } while (m++);
    cout << m << '\n';
  }
  return 0;
}