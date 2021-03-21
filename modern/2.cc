#include <iostream>

template <typename T, typename U> auto add2(T x, U y) -> decltype(x + y) {
  return x + y;
}
template <typename T, typename U> auto add3(T x, U y) { return x + y; }

auto main() -> int {
  auto w = add2<int, double>(1, 2.0);
  if (std::is_same<decltype(w), double>::value)
    std::cout << "w is double" << std::endl;

  auto x = add3<double, char>(5, 'c');
  std::cout << x - 'a' << std::endl;
  return 0;
}