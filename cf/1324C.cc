#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int t;
string jump;

void work() {
  cin >> t;

  while (t--) {
    cin >> jump;
    int tmp = 0;
    int ans = 0;

    for (int i = 0; i < jump.size(); i++) {
      if (jump[i] == 'L')
        tmp++;

      if (jump[i] == 'R' || i == jump.size() - 1) {
        ans = max(tmp, ans);
        tmp = 0;
      }
    }

    cout << ans + 1 << endl;
  }
}

int main(void) {
  work();
  return 0;
}