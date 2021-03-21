#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   * 返回总体积为V若干物品的最大总重量，如果g存在选择若干物品总体积为V的情况，返回-1
   * @param v int整型vector
   * @param g int整型vector
   * @param V int整型
   * @return int整型
   */

  typedef long long ll;
  int dp[1000000005];
  int Maximumweight(vector<int> &v, vector<int> &g, int V) {
    // write code here
    for (int i = 1; i <= v.size(); i++) {
      for (int j = V; j >= 0; j--) {
        dp[j] = max(dp[j], dp[j - g[i - 1]] + v[i - 1]);
      }
    }
    return dp[V];
  }
};

int main() {}