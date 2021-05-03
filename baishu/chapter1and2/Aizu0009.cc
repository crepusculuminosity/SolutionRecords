#include <bits/stdc++.h>
using namespace std;
int cnt;
constexpr int maxn=1e6+10;
int num[maxn],prime[maxn],dp[maxn];


void init() {
  for(int i=2;i<maxn;i++) {
    if(num[i]==0)  {
      prime[++cnt]=i;
      dp[i]=dp[i-1]+1;}
    else dp[i]=dp[i-1];
    for(int j=1;j<=cnt&&i*prime[j]<maxn;j++) {
      num[i*prime[j]]=1;
      if(i%prime[j]==0) break;
    }
  }
}

int main() {
  init();
  int n;
  while(~scanf("%d", &n)) {
    printf("%d\n",dp[n]);
  }
  return 0;
}