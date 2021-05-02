#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[45];

void init() {
  a[1] = 3, a[2] = 9;
  for (int i = 3; i <= 45; i++)
    a[i] = 2 * a[i - 1] + a[i - 2];
}

int main() {
  init();
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    int x;
    cin >> x;
    cout << a[x] << '\n';
  }
  return 0;
}