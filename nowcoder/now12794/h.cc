#include <iostream>
using namespace std;

int N, F, P;
int masks[12];
bool likes[12];

int main() {
  int i, j, k;
  int s, temp;
  char in[10];
  int cas = 0;
  while (true) {
    cin >> N >> F >> P;
    if (!N && !F && !P) {
      break;
    }
    for (i = 0; i < N; ++i) {
      cin >> s;
      masks[i] = 0;
      while (s--) {
        cin >> temp;
        temp--;
        masks[i] |= (1 << temp);
      }
      cin >> in;
      if (in[0] == 'Y')
        likes[i] = true;
      else
        likes[i] = false;
    }
    int res = 100;
    for (i = 0; i < F; ++i) {
      for (j = F; j <= N; ++j) {
        int mask = 0;
        bool anylike = false;
        for (k = i; k < j; k++) {
          if (likes[k])
            anylike = true;
          mask |= masks[k];
        }
        if (mask == (1 << P) - 1 && anylike) {
          res = min(res, 2 * (j - i - 1));
        }
      }
    }
    cas++;
    cout << "Test case #" << cas << ": ";
    if (res >= 100)
      cout << "Impossible\n\n";
    else
      cout << res << endl << endl;
  }
  return 0;
}
