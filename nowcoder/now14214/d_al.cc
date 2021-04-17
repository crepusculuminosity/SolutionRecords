#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#define maxm 60
#define maxn 100006
#define fr(i, a, b) for (i = a; i <= b; i++)
using namespace std;
typedef long long ll;

int n, m, s, ans, last[28], pr[maxn][28];
char st[maxn], sr[maxm], stt[maxm];
void pre() {
  int i, j;
  fr(j, 1, 26) last[j] = n + 1;
  for (i = n; i >= 0; i--) {
    fr(j, 1, 26) pr[i][j] = last[j];
    if (i != 0)
      last[st[i] - 'a' + 1] = i;
  }
  return;
}
bool check() {
  int i, j = 0;
  fr(i, 1, s) {
    j = pr[j][stt[i] - 'a' + 1];
    if (j == n + 1)
      return 0;
    if (stt[i] != stt[s - i + 1])
      return 0;
  }
  return 1;
}
void dfs(int x) {
  if (x == m + 1) {
    if (check())
      ans = max(ans, s);
    return;
  }
  stt[++s] = sr[x];
  dfs(x + 1);
  --s;

  dfs(x + 1);
  return;
}
int main() {

  scanf("%s", st + 1);
  scanf("%s", sr + 1);
  n = strlen(st + 1), m = strlen(sr + 1);
  pre();
  dfs(1);
  printf("%d\n", ans);
  return 0;
}