#include <stdio.h>
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
void out(int x) {
  if (x > 9)
    out(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  // freopen("data.in","r",stdin);
  int n = IStream::_getInt();
  // scanf("%d",&n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int a = IStream::_getInt();
    ans = ans ^ a;
  }
  printf("%d", ans);
  // out(ans);
  return 0;
}