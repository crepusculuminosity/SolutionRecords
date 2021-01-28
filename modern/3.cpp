#include <bits/stdc++.h>
//递归遍历所有模板参数
template <typename T0> void _printf1(T0 val) { std::cout << val << std::endl; }

template <typename T, typename... Ts> void _printf1(T val, Ts... args) {
  std::cout << val << std::endl;
  _printf1(args...);
}

template <typename T0, typename... T> void _printf2(T0 t0, T... t) {
  std::cout << t0 << std::endl;
  /*if constexpr(sizeof...(t))
    _printf2(t...);*/

  if constexpr (sizeof...(t))
    _printf2(t...);
}

int main() {
  //_printf1(3123,"adad",44,66);
  _printf2(3123, "adad", 44, 66);
  //_printf3(3123,"adad",44,66);

  return 0;
}