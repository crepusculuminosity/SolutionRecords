#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 10010;
int a[maxn];
int dp1[maxn], dp2[maxn];
int n;
void fun() {
  for (int i = 1; i <= n; i++) {
    dp1[i] = 1;
    for (int j = 1; j < i; j++) {
      if (a[j] < a[i])
        dp1[i] = max(dp1[i], dp1[j] + 1);
    }
  }
  for (int i = n; i >= 1; i--) {
    dp2[i] = 1;
    for (int j = n; j > i; j--) {
      if (a[j] < a[i])
        dp2[i] = max(dp2[i], dp2[j] + 1);
    }
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  while (cin >> n) {
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    int ans = -1;
    fun();
    for (int i = 1; i <= n; i++) {
      ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    cout << n - ans << '\n';
  }

  return 0;
}