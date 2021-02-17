#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 1e6 + 5;
ll a[maxn];
int n, k;

int check(ll x) {
  int res = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] - a[i - 1] >= x)
      res += (a[i] - a[i - 1]) / x;
    if ((a[i] - a[i - 1]) % x == 0)
      res--;
  }
  return res;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);

  ll mid, l = 0, r = 1e12;
  while (l < r) {
    mid = (l + r) / 2;
    if (check(mid) > k)
      l = mid + 1;
    else
      r = mid;
  }
  cout << r << endl;
  return 0;
}