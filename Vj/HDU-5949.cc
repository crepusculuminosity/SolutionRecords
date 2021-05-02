#include <bits/stdc++.h>
using namespace std;
char s[20];

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int _; cin>>_;
  while(_--) {
    int ans=0;
    cin>>(s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) {
      if(s[i]=='H') ans+=1;
      if(s[i]=='C') ans+=12;
      if(s[i]=='O') ans+=16;
    }
    cout<<ans<<endl;
  }
  return 0;
}