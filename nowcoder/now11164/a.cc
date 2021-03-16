#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5010;
char a[maxn];
int main() {
  char ch = getchar();
  getchar();
  scanf("%s", a);
  int ans = 0;
  for (int i = 0; a[i] != '\n'; i++)
    if (a[i] == ch)
      ++ans;
  printf("%d", ans);
  return 0;
}