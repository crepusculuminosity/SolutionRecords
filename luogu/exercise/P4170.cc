#include <bits/stdc++.h>
using namespace std;
char s[60];
int f[60][60];

int dfs(int l, int r) {
  if (~f[l][r])
    return f[l][r];
  if (l == r)
    return 1;
  int &res = f[l][r];
  res = 0x7fffffff;
  if (s[l] == s[r])
    res = min(dfs(l + 1, r), dfs(l, r - 1));
  for (int k = l; k < r; k++)
    res = min(res, dfs(l, k) + dfs(k + 1, r));
  return res;
}

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  memset(f, -1, sizeof(f));
  printf("%d", dfs(1, n));
  return 0;
}