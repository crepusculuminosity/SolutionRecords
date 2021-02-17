#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

template <typename T> T max(T &&a, T &&b) { return b < a ? a : b; }

template <typename T, typename U>
auto cmp(T a, U b) -> typename std::decay<decltype(1 ? a : b)>::type {
  return b < a ? a : b;
}

template <typename T1, typename T2,
          typename RT = std::decay_t<decltype(1 ? T1() : T2())>>
RT cokp(T1 a, T2 b) {
  return b < a ? a : b;
}

template <typename T1, typename T2, typename RT = std::common_type_t<T1, T2>>
RT codfp(T1 a, T2 b) {
  return b < a ? a : b;
}

template <typename T, typename U>
typename std::common_type<T, U>::type comp(T a, U b) {}
int main() {
  int i = 42;
  cout << ::max(5, 7) << endl;
  cout << ::max(std::move(i), 21) << endl;
  cout << cmp(1331, 242.5) << endl;
  auto a = ::cmp(313, 44.1);
  cout << a << endl;
  return 0;
}