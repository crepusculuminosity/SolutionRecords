#include <bits/stdc++.h>
//递归遍历所有模板参数
// template <typename T0> void _printf1(T0 val) { std::cout << val << std::endl;
// }
/*template <typename T, typename... Ts> void _printf1(T val, Ts... args) {
  std::cout << val << std::endl;
  _printf1(args...);
}*/
template <typename T0, typename... T> void _printf2(T0 t0, T... t) {
  std::cout << t0 << std::endl;
  if constexpr (sizeof...(t))
    _printf2(t...);
}
template <typename T, typename... Ts> void read(T &x, Ts &...t) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
  if constexpr (sizeof...(t))
    read(t...);
}
int main() {
  int a, b, c;
  read(a, b, c);
  std::cout << a << ' ' << b << ' ' << c << std::endl;
  return 0;
}