#include <bits/stdc++.h>
using namespace std;
int a[5], b[5];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < 4; ++i)
    cin >> a[i];
  for (int i = 1; i < 4; ++i)
    cin >> b[i];

  int x = min(a[1], b[2]), y = min(a[2], b[3]), z = min(a[3], b[1]);
  int w = x + y + z;
  a[1] -= x;
  b[2] -= x;
  a[2] -= y;
  b[3] -= y;
  a[3] -= z;
  b[1] -= z;
  int d = min(a[1], b[1]) + min(a[2], b[2]) + min(a[3], b[3]);

  cout << 2 * w + d << endl;
  return 0;
}