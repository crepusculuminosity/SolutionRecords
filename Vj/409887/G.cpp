#include <iostream>
using namespace std;
int main() {
  int a[10] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
  int n;
  while (cin >> n && n != 0) {
    cout << a[n - 1] << endl;
  }
  return 0;
}