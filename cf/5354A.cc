#include <bits/stdc++.h>
using namespace std;

char ch[10];

int main() {
  int n;
  while (cin >> n) {
    int cnt = 0;
    int ans = 0;
    while (n) {
      int x = n % 10;
      n /= 10;
      if (x == 4)
        ans &= (1 << cnt);
      else
        ans |= (1 << cnt);
      ++cnt;
    }
   cout << cnt << ' ';
    ans += (1 << cnt) - 1;
    cout << ans << endl;
  }
  return 0;
}