#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int a[N];
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0, sum; i < n; ans++) {
    sum = 0;
    while (i < n && sum + a[i] <= m)
      sum += a[i++];
  }
  cout << ans;
  return 0;
}