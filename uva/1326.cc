#include <bits/stdc++.h>
using namespace std;
#define lb(x) ((x) & (-x))
constexpr int maxn = 30;
map<int, int> tb;
char s[1000];
int n, a[maxn];

inline int bitcount(int x) {
  int res = 0;
  for (; x; x -= lb(x))
    ++res;
  return res;
}

int main() {
  while (scanf("%d", n) == 1 && n) {
    for (int i = 1; i <= n; i++) {
      scanf("%s", s);
      a[i] = 0;
      int len = strlen(s);
      for (int j = 0; j < len; j++)
        a[i] ^= 1 << (s[j] - 'A');
    }

    tb.clear();
    int mid = n / 2;
    int lim = (1 << mid);
    for (int i = 0; i <= lim; i++) {
      int x = 0;
      for (int j = 1; j <= mid; j++)
        if (i & (1 << (j - 1)))
          x ^= a[j];
      if (!tb.count(x) || bitcount(tb[x]) < bitcount(i))
        tb[x] = i;
    }
  }
}