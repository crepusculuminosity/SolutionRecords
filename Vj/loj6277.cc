#include <bits/stdc++.h>
using namespace std;
template <typename T, typename... Ts> inline void read(T &x, Ts &...args) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
  if constexpr (sizeof...(Ts) > 1)
    read(args...);
}