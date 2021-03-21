#include <bits/stdc++.h>

class A {
public:
  int *p;
  A() : p(new int(1)) { std::cout << "constructed" << std::endl; }
  A(A &a) : p(new int(*a.p)) { std::cout << "copied" << std::endl; }
  A(A &&a) : p(a.p) {
    a.p = nullptr;
    std::cout << "move" << std::endl;
  }
  ~A() {
    std::cout << "deconstructed" << std::endl;
    delete p;
  }
};

A return_rvalue(bool test) {
  A a, b;
  if (test)
    return a;
  else
    return b;
}

int main() {
  A obj = return_rvalue(0);
  std::cout << obj.p << std::endl;
  std::cout << *obj.p << std::endl;
  // std::forward()
  return 0;
}