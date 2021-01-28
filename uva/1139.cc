#define RF freopen("data.in", "r", stdin);
#define WF freopen("data.out", "w", stdout);
#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
char a[maxn], b[maxn];
int aa[30], bb[30];
int main() {
  RF while (~scanf("%s %s", a, b)) {
    memset(aa, 0, sizeof(aa));
    memset(bb, 0, sizeof(bb));
    int f = 1;
    int len = strlen(a);
    for (int i = 0; i < len; i++)
      aa[a[i] - 'A']++, bb[b[i] - 'A']++;
    sort(aa, aa + 26);
    sort(bb, bb + 26);
    for (int i = 0; i < 26; i++) {
      if (aa[i] != bb[i]) {
        f = 0;
        break;
      }
    }
    if (f)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}