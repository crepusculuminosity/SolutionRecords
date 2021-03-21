#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   * 给定一个后缀表达式，返回它的结果
   * @param str string字符串
   * @return long长整型
   */
  typedef long long ll;
  stack<ll> s;
  long long solve(string str) {
    // write code here
    ll x = 0;
    for (auto iter = str.begin(); iter != str.end(); iter++) {
      if ((*iter) >= '0' && (*iter) <= '9') {
        x = x * 10 + (*iter) - '0';
      }
      if (*iter == '#') {
        s.push(x);
        x = 0;
      }
      if (*iter == '+') {
        ll a = s.top();
        s.pop();
        ll b = s.top();
        s.pop();
        s.push(a + b);
      }
      if (*iter == '-') {
        ll a = s.top();
        s.pop();
        ll b = s.top();
        s.pop();
        s.push(b - a);
      }

      if (*iter == '*') {
        ll a = s.top();
        s.pop();
        ll b = s.top();
        s.pop();
        s.push(a * b);
      }
    }
    return s.top();
  }
};

int main() {
  Solution so;
  string s = "1#1#+";
  cout << so.solve(s) << endl;
  return 0;
}