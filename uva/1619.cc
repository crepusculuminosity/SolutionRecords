#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
typedef long long ll;
const int maxn = 1e5 + 10;
int a[maxn], n, L[maxn], R[maxn];
ll sum[maxn];

inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int T = 0;
  // n = read();
  while (~scanf("%d", &n)) {
    if (T++)
      puts("");
    for (int i = 1; i <= n; i++)
      a[i] = read(), sum[i] = sum[i - 1] + 1LL * a[i];
    a[0] = a[n + 1] = -1;
    for (int i = 1; i <= n + 1; i++) {
      while (!s.empty() && a[s.top()] > a[i])
        R[s.top()] = i - 1, s.pop();
      s.push(i);
    }
    for (int i = n; i >= 0; i--) {
      while (!s.empty() && a[s.top()] > a[i])
        L[s.top()] = i + 1, s.pop();
      s.push(i);
    }
    ll ans = -1;
    int l, r;
    // for (int i = 1; i <= n; i++)
    //  cout << i << ' ' << L[i] << ' ' << R[i] << endl;
    for (int i = 1; i <= n; i++) {
      ll tmp = 1LL * a[i] * (sum[R[i]] - sum[L[i] - 1]);
      if (tmp > ans)
        ans = tmp, r = R[i], l = L[i];
      else if (tmp == ans) {
        if (r - l > R[i] - L[i])
          r = R[i], l = L[i];
        else if (r - l == R[i] - L[i] && L[i] + 1 < l)
          r = R[i], l = L[i];
      }
    }
    printf("%lld\n%d %d\n", ans, l, r);
  }

  return 0;
}