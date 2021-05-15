#include <iostream>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {

      bool flag = false;
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        if (c == '/' || c == '\\') {
          ans++;
          flag = !flag;
        }
        if (c == '.' && flag)
          ans += 2;
      }
    }
    cout << ans / 2 << endl;
  }
  return 0;
}