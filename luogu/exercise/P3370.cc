#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull base = 131;
const ull mod = 212370440130137957ll;
ull a[10010];
char s[10010];
int n, ans = 1;
ull _hash(char s[]) {
  int len = strlen(s);
  ull ans = 0;
  for (int i = 0; i < len; i++) {
    ans = (ans * base + (ull)s[i]) % mod;
  }
  return ans;
}

int main() {
  // freopen("data.in","r",stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    a[i] = _hash(s);
  }
  sort(a + 1, a + 1 + n);
  for (int i = 2; i <= n; i++) {
    if (a[i] != a[i - 1])
      ans++;
  }
  printf("%d\n", ans);
}