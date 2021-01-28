#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;
int main() {
  long long int n, h = 0;
  cin >> n;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      h = h + i;
      h = h + n / i;
      if (i == n / i)
        h = h - i;
    }
  }
  cout << h << endl;
  return 0;
}