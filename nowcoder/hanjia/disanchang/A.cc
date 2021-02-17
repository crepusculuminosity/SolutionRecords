#define Rf freopen("data.in", "r", stdin);
#define Wf wfopen("data.out", "w", stdout);
#include <bits/stdc++.h>
using namespace std;

int gs(int n) {
  int res = 0;
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}
int main() {
  int n, r;
  cin >> n;
  for (r = n + 1;; r++) {
    if (gs(r) == gs(n)) {
      cout << r;
      break;
    }
  }
  return 0;
}