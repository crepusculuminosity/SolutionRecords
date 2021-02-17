#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 20;
int a[maxn][maxn], b[maxn][maxn];
int n;
constexpr int MAXN = 1000;

int check(int num) {
  int ans = 0;
  memset(a, 0, sizeof(a));
  for(int i=1;i<=n;i++) {
    if(num&(1<<(i-1))) a[1][i]=1;
    if(!a[1][i]&&b[1][i]) return MAXN;
    if(a[1][i]&&!b[1][i]) ans++;
  }
  for(int i=2;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      a[i][j]=(a[i-2][j]+a[i-1][j-1]+a[i-1][j+1])&1;
      if(!a[i][j]&&b[i][j]) return MAXN;
      if(a[i][j]&&!b[i][j]) ans++;
    }
  }
  return ans;
}

int main() {
  //freopen("data.in", "r", stdin);
  int _, kase = 1;
  scanf("%d", &_);
  while (_--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        scanf("%d", &b[i][j]);
    }

    int ans = MAXN;
    for (int s = 0; s < (1 << n); s++)
      ans = min(ans, check(s));
    if (ans == MAXN)
      ans = -1;
    printf("Case %d: %d\n", kase++, ans);
  }
  return 0;
}