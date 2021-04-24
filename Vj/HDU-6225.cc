#include <bits/stdc++.h>
using namespace std;

using lll = __int128_t;

inline lll read() {
  lll x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = x * 10 + ch - 48, ch = getchar();
  return x;
}

inline void print(lll x) {
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + 48);
}


int main() {
  //freopen("data.in","r",stdin);
  int _;
  cin>>_;
  while(_--) {
    lll ans=0;
    for(int i=0;i<4;i++) ans+=read();
    print(ans);
    cout<<'\n';
  }
  return 0;
}