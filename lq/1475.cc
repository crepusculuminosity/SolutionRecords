#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll res;

bool check(int n) {
  while (n) {
    int t = n % 10;
    if (t == 0 || t == 1 || t == 2 || t == 9)
      return 1;
    n /= 10;
  }
  return 0;
}

int main() {
  for (int i = 2019; i >= 1; i--)
    if (check(i))
      res += (ll)i * i * i;
  cout << res;
}
