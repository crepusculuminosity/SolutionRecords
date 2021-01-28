#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 10;
int a[maxn];
int w, n;

int main() {
  cin >> w >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);

  int l = 1, r = n, ans = 0;
  while (l != r) {
    if (a[l] + a[r] <= w)
      l++, r--, ans++;
    else
      r--, ans++;
  }
  cout << ans;
  return 0;
}