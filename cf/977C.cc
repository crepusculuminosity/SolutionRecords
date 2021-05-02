#include <bits/stdc++.h>
using namespace std;
int n, k;
constexpr int maxn = 2e5 + 10;
int a[maxn];

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int ans;
  if (k)
    ans = a[k];
  else
    ans = a[1] - 1;
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] <= ans)
      ++cnt;
  if (cnt != k) {
    cout << "-1";
    return 0;
  }
  cout << ans;
  return 0;
}