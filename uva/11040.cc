#include <bits/stdc++.h>
using namespace std;
int a[10][10];

void solve() {
  for (int i = 3; i <= 9; i += 2) {
    for (int j = 2; j <= i; j += 2)
      a[i][j] = (a[i - 2][j - 1] - a[i][j - 1] - a[i][j + 1]) / 2;
  }
  for (int i = 2; i <= 9; i += 2) {
    for (int j = 1; j <= i; j++)
      a[i][j] = a[i + 1][j] + a[i + 1][j + 1];
  }
}

int main() {
  //freopen("data.in", "r", stdin);
  // freopen("data.out","w",stdout);
  int _;
  cin >> _;
  while (_--) {
    for (int i = 1; i <= 9; i += 2)
      for (int j = 1; j <= i; j += 2)
        cin >> a[i][j];
    solve();
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= i - 1; j++) {
        cout << a[i][j] << ' ';
      }
      cout << a[i][i] << endl;
    }
  }
  return 0;
}