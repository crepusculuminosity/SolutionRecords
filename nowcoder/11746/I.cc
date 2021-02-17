#include <bits/stdc++.h>
using namespace std;

int a[20];

int main() {
  a[1] = 1;
  for (int i = 2; i <= 15; i++)
    a[i] = 2 * a[i - 1] + 1;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int f = 0;
    for (int i = 2; i <= 15; i++) {
      if (n % a[i] == 0) {
        f = 1;
        break;
      }
    }
    if (f)
      cout << "YE5" << endl;
    else
      cout << "N0" << endl;
  }
  return 0;
}