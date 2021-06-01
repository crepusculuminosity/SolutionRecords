#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
stack<int> s;
const int maxn = 1e5 + 10;
int a[maxn], L[maxn], R[maxn];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}
int n;

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  // int n = read();
  while (~scanf("%d", &n) && n) {
    // while()
    for (int i = 1; i <= n; i++)
      a[i] = read();
    a[n + 1] = a[0] = 0; //多组数据
    for (int i = 1; i <= n + 1; i++) {
      while (!s.empty() && a[s.top()] > a[i])
        R[s.top()] = i, s.pop();
      s.push(i);
    }
    for (int i = n; i >= 0; i--) {
      while (!s.empty() && a[s.top()] > a[i])
        L[s.top()] = i, s.pop();
      s.push(i);
    }
    ll ans = -1;
    for (int i = 1; i <= n; i++)
      ans = max(ans, (ll)a[i] * (R[i] - L[i] - 1));
    printf("%lld\n", ans);
  }
  return 0;
}