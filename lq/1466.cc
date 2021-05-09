#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
typedef long long ll;
ll a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  int k = 1;
  ll g = a[2] - a[1];
  for (int i = 3; i <= n; i++)
    g = __gcd(g, a[i] - a[i - 1]);
  if (g == 0)
    cout << n;
  else
    cout << (a[n] - a[1]) / g + 1;
  return 0;
}
