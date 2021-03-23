#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1010;
int a[maxn];
int main() {
  int n;
  while (cin >> n) {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - 1 - a;
    for (int i = 1; i <= n; i++)
      cout << a[i] << endl;
  }
  return 0;
}