#include <bits/stdc++.h>
using namespace std;

int a[1001];

int main() {
  int n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    a[x] += y;
  }
  for (int i = 0; i < 1001; i++)
    if (a[i])
      cout << i << ' ' << a[i] << endl;
  return 0;
}