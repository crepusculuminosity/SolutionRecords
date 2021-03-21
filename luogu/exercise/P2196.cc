/*#include <bits/stdc++.h>
using namespace std;

int t,dp[30],w[30],a[30][30],pre[30],n,maxw,ans;

void print(int x){
    if(pre[x]==0){
        cout<<x;
        return;
    }
    print(pre[x]);
    cout<<" "<<x;
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>w[i];
   // memset(a,1,sizeof(a));
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)
            cin>>a[i][j];
    }
    dp[1]=w[1];
    for(int i=2;i<=n;i++){

        for(int j=1;j<i;j++){
            if(dp[j]*a[j][i]>maxw){
                maxw=dp[j]*a[j][i];
                pre[i]=j;
            }
        }

        dp[i]=maxw+w[i];
        if(dp[i]>ans){
            ans=dp[i];
            t=i;
        }
    }
    print(t);
    cout<<endl<<ans<<endl;
    return 0;

}*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, a[205], g[205][205], pre[205], t, f[205], ans;
void print(int x) {
  if (pre[x] == 0) {
    printf("%d", x);
    return;
  }
  print(pre[x]);
  printf(" %d", x);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int x;
      scanf("%d", &x);
      if (x == 1)
        g[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (g[j][i] && f[j] > f[i]) {
        f[i] = f[j];
        pre[i] = j;
      }
    }
    f[i] += a[i];
    if (f[i] > ans) {
      ans = f[i];
      t = i;
    }
  }
  print(t);
  printf("\n%d", ans);
  return 0;
}