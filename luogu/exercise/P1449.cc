#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char ch;
stack<int> s;
int c;
int x, y;

int main() {
  while (ch != '@') {
    /* code */
    ch = getchar();
    switch (ch) {
    case '+':
      x = s.top();
      s.pop();
      y = s.top();
      s.pop();
      s.push(x + y);
      break;
    case '-':
      x = s.top();
      s.pop();
      y = s.top();
      s.pop();
      s.push(y - x);
      break;
    case '*':
      x = s.top();
      s.pop();
      y = s.top();
      s.pop();
      s.push(x * y);
      break;
    case '/':
      x = s.top();
      s.pop();
      y = s.top();
      s.pop();
      s.push(y / x);
      break;
    case '.':
      s.push(c);
      c = 0;
      break;
    default:
      c = c * 10 + ch - '0';
      break;
    }
  }
  cout << s.top() << endl;
  return 0;
}