#include <algorithm>
#include <array>
#include <initializer_list>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <vector>

constexpr int foo(int i) { return 5 + i; }

constexpr int fibbo(const int n) {
  if (n == 1)
    return 1;
  if (n == 2)
    return 1;
  return fibbo(n - 1) + fibbo(n - 2);
}

class Foo {
public:
  std::vector<int> vec;
  Foo(std::initializer_list<int> list) {
    for (std::initializer_list<int>::iterator iter = list.begin();
         iter != list.end(); ++iter)
      vec.push_back(*iter);
  }
};

std::tuple<int, double, std::string> f() {
  return std::make_tuple(1, 54.11, "hehe");
}

int main() {
  // std::array需要编译器常值才能编译通过

  std::vector<int> vec = {1, 2, 3, 4, 5};

  if (const std::vector<int>::iterator iter =
          std::find(vec.begin(), vec.end(), 3);
      iter != vec.end())
    *iter = 4; // if/switch内直接开临时变量

  Foo foo = {1, 2, 3, 4, 5};
  for (std::vector<int>::iterator iter = foo.vec.begin(); iter != foo.vec.end();
       iter++)
    ;

  auto [x, y, z] = f();

  // std::cout<<a<<b<<c<<std::endl;

  return 0;
}