#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;
typedef long long ll;
ll sum[MAXN];
int n, s;
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9')
    c = getchar();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}

inline int find_(int x) {
  int l = 0, r = n, mid, ans = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (sum[mid] <= x) {
      l = mid + 1;
      ans = mid;
    } else
      r = mid - 1;
  }
  return ans;
}

int main() {
  // freopen("data.in","r",stdin);
  int _ = read();
  while (_--) {
    scanf("%d%d", &n, &s);
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) {
      // int x=read();
      int x;
      // scanf("%d",&x);
      x = read();
      sum[i] = sum[i - 1] + x;
    }
    int ans = 1 + n, i = 1;
    for (int j = 1; j <= n; j++) {
      if (sum[i] > sum[j] - s)
        continue;
      while (sum[i] <= sum[j] - s)
        i++;
      ans = min(ans, j - i + 1);
    }
    printf("%d\n", ans == n + 1 ? 0 : ans);
  }
  return 0;
}