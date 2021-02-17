#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 10010;
int a[maxn], b[maxn];
int n;
int ans = 0;
int solve(int k) {
  memset(a, 0, sizeof(a));
  a[1] = k;
  for (int i = 2; i <= n; i++) {
    int tmp = b[i - 1] - a[i - 2] - a[i - 1];
    if (tmp < 0 || tmp > 1)
      return 0;
    a[i] = tmp;
  }
  if (a[n] + a[n - 1] == b[n])
    return 1;
  return 0;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  for (int i = 0; i < 2; i++)
    ans += solve(i);
  cout << ans;
  return 0;
}