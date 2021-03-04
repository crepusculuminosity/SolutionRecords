#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1010;

int t,m;
int dp[105][maxn];
int w[105],v[105];
/*
int main() {
  //freopen("data.in", "r", stdin);
  cin>>t>>m;
  for(int i=1;i<=m;i++) 
    cin>>w[i]>>v[i];
  for(int i=1;i<=m;i++) 
    for(int j=1;j<=t;j++) {
      dp[i][j]=dp[i-1][j];
      if(j>=w[i])
        dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
    }
  cout<<dp[m][t];
  return 0;
  
}*/

int dfs(int i,int j) {
  if(~dp[i][j]) return dp[i][j];
  if(i==0||j==0) return 0;
  if(j<w[i]) return dfs(i-1,j);
  int &res=dp[i][j];
  res=0;
  res=max(dfs(i-1,j),dfs(i-1,j-w[i])+v[i]);
  return res;
}

int main() {
  //freopen("data.in", "r", stdin);
  cin>>t>>m;
  for(int i=1;i<=m;i++) 
    cin>>w[i]>>v[i];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(m,t);
  return 0;
}