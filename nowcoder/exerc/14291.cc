#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 100000 + 10;
ll a[maxn];
ll sum;
int n;

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  int x;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  ll res = 0;
  for (int i = 1; i <= n; i++)
    res += i * a[i];
  cout << res - a[n];
  return 0;
}