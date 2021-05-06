#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  printf("%.9lf", a + b - sqrt(a * a + b * b));
  return 0;
}