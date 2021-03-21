#include <bits/stdc++.h>
using namespace std;
namespace IStream {
const int L = 1 << 31 - 1;
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

namespace FstIO {
constexpr int L = 1 << 15;
char buffer[L], *S, *T;
inline char gc() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, L, stdin);
    if (S == T)
      return EOF;
  }
  return *S++;
}
template <typename T, typename... Ts> inline void read(T &x, Ts &...t) {
  x = 0;
  T f = 1;
  char c = gc();
  while (!isdigit(c)) {
    if (c == '-')
      f = -1;
    c = gc();
  }
  while (isdigit(c))
    x = (x << 1) + (x << 3) + c - 48, c = gc();
  x *= f;
  if constexpr (sizeof...(t))
    read(t...);
}
} // namespace FstIO
using FstIO::read;

inline void out(int x) {
  if (x > 9)
    out(x / 10);
  putchar(x % 10 + '0');
}

const int MAXN = 100005;
int a[MAXN];
int n;

void _swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void _qSort(int l, int r) {
  if (l >= r)
    return;
  int mid = a[(l + 2 * r) / 3];

  int p = l, q = r;

  do {
    while (a[p] < mid)
      p++;
    while (a[q] > mid)
      q--;

    if (p <= q) {
      _swap(a[p], a[q]);
      p++;
      q--;
    }
  } while (p <= q);

  if (l < q)
    _qSort(l, q);
  if (p < r)
    _qSort(p, r);
}

int main() {
  // freopen("")
  read(n);
  for (int i = 1; i <= n; i++)
    // scanf("%d",&a[i]);
    read(a[i]);
  _qSort(1, n);
  // sort(a+1,a+1+n);

  for (int i = 1; i <= n; i++)
  // printf("%d ",a[i]);
  {
    out(a[i]);
    putchar(' ');
  }
  return 0;
}