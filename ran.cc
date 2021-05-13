#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("data.out","w",stdout);
  string str("duyangli");
  for (int i = 1; i <= 20; i++) {
    random_shuffle(str.begin(), str.end());
    cout << str << endl << endl;
  }
  return 0;
}