using namespace std;
#include <bits/stdc++.h>
typedef long long LL;
const LL p = 1e9 + 7;

LL solve(LL a, LL b, LL p) { //快速幂
  LL ans = 1;
  while (b) {
    if (b & 1) {
      ans = ((__int128_t)ans * a % p);
    }
    a = ((__int128_t)a * a % p);
    b = b >> 1;
  }
  return ans;
}

int main() {
  int t;

  LL n;
  cin >> n;
  cout << solve(2, n, p) - 1 << endl;

  return 0;
}
