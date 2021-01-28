#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   * 返回将这个数n拆成两个自然数之和一共有多少种拆法（符合规则）。
   * @param n int整型 代表题意中的n
   * @return int整型
   */
  int g[1000006];
  int solve(string s) {
    // write code here
    for (int i = 1, j = 0; i < s.size();) {
      if (s[i] == s[j])
        g[i++] = ++j;
      else if (j == 0)
        i++;
      else
        j = g[j - 1];
    }
    int l = g[s.size() - 1];
    if (l == 0)
      return -1;
    return l;
  }
};

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  string str;
  cin >> str;
  Solution s;
  cout << s.solve(str) << endl;
  return 0;
}