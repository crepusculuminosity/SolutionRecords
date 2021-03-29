#include <bits/stdc++.h>
using namespace std;
constexpr int N = 32000;

int a[N];
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  for (int i = 1; i < N; i++)
    a[i] = i;
  int _;
  cin >> _;
  while (_--) {
    int l, r;
    cin >> l >> r;
    int L = 0, R = N;
    L = lower_bound(a, a + N, sqrt(l)) - a;
    R = upper_bound(a, a + N, sqrt(r)) - a;
    cout << max(0, R - L) << endl;
  }
  return 0;
}