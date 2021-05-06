#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 110;
char a[maxn], b[maxn];

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int _, kse = 1;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i], b[i] = a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] != b[i])
        ans++;
    cout << "Case " << kse++ << ": " << ans << '\n';
  }
  return 0;
}