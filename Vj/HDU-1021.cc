#include <bits/stdc++.h>
using namespace std;
int a,b;

int main() {
  
  while(cin>>a>>b&&a) {
    int res=1;
    while(b) {
      if(b&1) res=res*a%1000;
      a=a*a%1000;
      b>>=1;
    }
    cout<<res<<'\n';
  }
  return 0;
}