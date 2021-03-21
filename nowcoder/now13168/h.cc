#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=550;
int a[maxn][maxn],dp[maxn][maxn];


int main() {
  int n; cin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>a[i][j];
  for(int t=1;t<=n-1;t++) 
    for(int i=1;i<=n-t;i++) 
      for(int j=i;j<=i+t;j++) 
        dp[i][i+t]=max(dp[i][i+t],dp[i+1][j-1]+dp[j+1][i+t]+a[i][j]);
      
  cout<<dp[1][n];
  return 0;
  
}