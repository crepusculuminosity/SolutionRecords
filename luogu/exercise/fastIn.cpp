#include <bits/stdc++.h>
using namespace std;
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
}
} // namespace IStream

inline int read() {
  int x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

void out(int x) {
  if (x > 9)
    out(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  int a = IStream::_getInt();
  printf("%d\n", a);
  return 0;
}

template <class T> inline bool read(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) {
    if (c == EOF)
      return false;
    f ^= c == '-', c = getchar();
  }
  while (isdigit(c))
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (f)
    x = -x;
  return true;
}
template <class T> inline void print(T x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 ^ 48);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T, class... S> inline bool read(T &x, S &...y) {
  return read(x) && read(y...);
}