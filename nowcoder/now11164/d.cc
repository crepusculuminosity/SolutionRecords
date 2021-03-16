#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 100100;
int dp[maxn];
int a[maxn];
int ans;
namespace IStream {
const int L = 1 << 15;
char buffer[L], *S, *T;
inline char _getChar() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, L, stdin);
    if (S == T)
      return EOF;
  }
  return *S++;
}

inline int _getInt() {
  char ch;
  int re = 0, f = 1;
  for (ch = _getChar(); ch < '0' || ch > '9'; ch = _getChar())
    ;
  while (ch >= '0' && ch <= '9') {
    re = (re << 1) + (re << 3) + (ch - '0');
    ch = _getChar();
  }
  return re;
}
} // namespace IStream

void solve(int x) {
  int m = sqrt(x), sum = 0;
  for (int i = 2; i <= m; ++i)
    if (!(x % i))
      sum = max(max(sum, dp[i]), dp[x / i]);
  sum = max(sum, dp[x]);
  for (int i = 2; i <= m; ++i) {
    if (x % i == 0) {
      dp[i] = sum + 1;
      while (!(x % i))
        x /= i;
    }
  }
  dp[x] = sum + 1;
  ans = max(ans, sum + 1);
}

int main() {
  // freopen("data.in", "r", stdin);
  int _ = IStream::_getInt();
  while (_--) {
    memset(dp, 0, sizeof(dp));
    int n = IStream::_getInt();
    for (int i = 1; i <= n; ++i)
      a[i] = IStream::_getInt();
    ans = 0;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
      solve(a[i]);
    printf("%d\n", ans);
  }
  return 0;
}