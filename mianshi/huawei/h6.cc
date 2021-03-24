#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      cout << i << ' ';
      n /= i;
    }
  }
  if (n > 1)
    cout << n << ' '; //最后一个有空格
  return 0;
}