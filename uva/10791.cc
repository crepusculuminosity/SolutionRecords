#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
long long n, ans, cnt, q;
int num;
void solve() {
  int tmp = n;
  while (n % q == 0)
    n /= q;
  if (tmp / n > 1)
    ans += (tmp / n), num++;
  return;
} //加上px^ax
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n && n != 0) {
    cnt++;
    ans = 0;
    for (q = 2; q <= sqrt(n); q++)
      solve();
    if (n > 1)
      ans += n, num++;
    if (num == 0)
      ans += 2;
    if (num == 1)
      ans += 1; //特判
    printf("Case %lld: %lld\n", cnt, ans);
    num = 0; //清零
  }
  return 0;
}