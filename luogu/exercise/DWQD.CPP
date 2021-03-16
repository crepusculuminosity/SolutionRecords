#include <bits/stdc++.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
struct NoobIO {
  char *p;
  NoobIO() {
    p = (char *)mmap(NULL, lseek(0, 0, SEEK_END), PROT_READ, MAP_PRIVATE, 0, 0);
  }
  template <typename T, typename... Ts> inline void read(T &x, Ts &...t) {
    x = 0;
    T f = 1;
    char ch = *p++;
    while (ch < '0' || ch > '9') {
      if (ch == '-')
        f = -1;
      ch = *p++;
    }
    while (ch >= '0' && ch <= '9')
      x = x * 10 + ch - 48, ch = *p++;
    x *= f;
    if constexpr (sizeof...(t))
      read(t...);
  }
};

int main() {
  freopen("data.in", "r", stdin);
  NoobIO io;
  int n, m, k;
  io.read(n, m, k);
  return 0;
}