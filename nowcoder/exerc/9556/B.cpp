#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   * 返回符合题意的最长的子串长度
   * @param x string字符串
   * @return int整型
   */
  int Maximumlength(string x) {
    // write code here
    int a, b, c, maxlen = -1, len;
    for (int i = 0; i < x.size(); i++) {
      a = 0, b = 0, c = 0;
      for (int j = i; j < x.size(); j++) {
        len = 0;
        if (x[j] == 'n')
          a++;
        if (x[j] == 'p')
          b++;
        if (x[j] == 'y')
          c++;

        if (a && b && c)
          break;

        else
          len++;
      }
      maxlen = max(maxlen, len);
    }
    return maxlen;
  }
};

int main() {
  string str = "abcdefghijklmn";
  Solution s;
  cout << s.Maximumlength(str) << endl;
  return 0;
}