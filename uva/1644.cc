#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1300000;
int num[maxn],prime[maxn],cnt;

void init() {
  for(int i=2;i<maxn;i++) {
    if(!num[i]) prime[++cnt]=i;
    for(int j=1;j<=cnt&&i*prime[j]<maxn;j++) {
      num[i*prime[j]]=1;
      if(i%prime[j]==0) break;
    }
  }
}

int main() {
  //freopen("data.in","r",stdin);
  //freopen("data.out","w",stdout);

  init();
  int x;
  while(cin>>x&&x) {
    if(!num[x]) cout<<"0\n";
    else {
      int i=x,j=x;
      while(num[i]) --i;
      while(num[j]) ++j;
      cout<<j-i<<'\n';
    }
  }
  return 0;
}