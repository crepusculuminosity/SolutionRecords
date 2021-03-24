#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int a = 0, b = 0, sum = 0;
  while (cin >> n) {
    if (n < 0)
      ++a;
    else
      ++b, sum += n;
  }
  cout << a << endl;
  if (b == 0)
    cout << fixed << setprecision(1) << 0.0;
  else
    cout << fixed << setprecision(1) << sum * 1.0 / b;
  return 0;
}