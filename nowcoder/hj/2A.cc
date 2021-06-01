#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      if (i + j & 1)
        cout << "1";
      else
        cout << "0";
    cout << '\n';
  }
  return 0;
}