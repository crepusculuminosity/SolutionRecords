#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
int num[maxn], h[maxn], hh[maxn], sum[maxn], cnt;

void init() {
  for (int i = 5; i < maxn; i += 4) {
    if (!num[i]) {
      h[++cnt] = i;
      for (int j = 5 * i; j < maxn; j += 4 * i)
        num[j] = 1;
    }
  }
  for (int i = 1; i <= cnt; i++) {
    for (int j = 1; j <= i && h[i] * h[j] < maxn; j++)
      hh[h[i] * h[j]] = 1;
  }
  for (int i = 1; i < maxn; i++)
    hh[i] += hh[i - 1];
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  init();
  int n;
  while (cin >> n && n) {
    cout << n << ' ' << hh[n] << '\n';
  }
  return 0;
}