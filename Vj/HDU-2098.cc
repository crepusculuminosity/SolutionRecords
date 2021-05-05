#include <bits/stdc++.h>
using namespace std;
int num[10010], prime[10010], cnt;

void init() {
  for (int i = 2; i <= 10000; i++) {
    if (num[i] == 0) {
      prime[++cnt] = i;
      for (int j = i * i; j <= 10000; j += i)
        num[j] = 1;
    }
  }
}

int main() {
  init();
  int n;
  while (cin >> n && n) {
    int ans = 0;
    for (int i = 2; i < n / 2; i++) {
      if (!num[i] && !num[n - i])
        ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}