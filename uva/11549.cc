#include <bits/stdc++.h> //开O2速度下降
using namespace std;
typedef long long ll;
int lim;
namespace IStream {
const int L = 1 << 15;
char buffer[L], *S, *T;
inline char _getChar() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, L, stdin);
    if (S == T)
      return EOF;
  }
  return *S++;
}

inline int _getInt() {
  char ch;
  int re = 0, f = 1;
  for (ch = _getChar(); ch < '0' || ch > '9'; ch = _getChar())
    ;
  while (ch >= '0' && ch <= '9') {
    re = (re << 1) + (re << 3) + (ch - '0');
    ch = _getChar();
  }
  return re;
  /*ch=_getChar();
while (ch<'0'||ch>'9') {
    if(ch=='-') f=-1;
    ch=_getChar();

}
while (ch>='0'&&ch<='9') {
    re=(re<<1)+(re<<3)+ch-'0';
    ch=_getChar();
}
return re*f;*/
}
} // namespace IStream
/*int buf[25];
int getnext(int n,int k) {
    int l=0;
    ll a=(ll)k*k;
    while(a) {buf[++l]=a%10;a/=10;}
    if(n>l) n=l;
    int ans=0; for(int i=1;i<=n;i++) ans=ans*10+buf[l--];
    return ans;
}*/

int _getnext(int k) {
  if (k == 0)
    return 0;
  ll x = (ll)k * k;
  while (x >= lim)
    x /= 10;
  return (int)x;
}

inline int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9')
    c = getchar();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}

int main() {
  // freopen("data.in","r",stdin);
  // int _; scanf("%d",&_);
  // int _=read();
  int _ = IStream::_getInt();
  while (_--) {
    // set<int> s;
    // memset(buf,0,sizeof(buf));
    // int n,k; scanf("%d%d",&n,&k);
    // int n=read(),k=read();
    int n = IStream::_getInt(), k = IStream::_getInt();
    lim = 1;
    for (int i = 0; i < n; i++)
      lim *= 10;
    int ans = k;
    /* while(!s.count(k)) {
     s.insert(k);
     if(k>ans) ans=k;
     k=_getnext(k);
 }*/
    int k1 = k, k2 = k;
    do {
      k1 = _getnext(k1);
      k2 = _getnext(k2);
      if (k2 > ans)
        ans = k2;
      k2 = _getnext(k2);
      if (k2 > ans)
        ans = k2;
    } while (k1 != k2);
    printf("%d\n", ans);
  }
  return 0;
}