#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string pre, inor;
void work(string pre, string inor) {
  if (pre.empty())
    return;
  //如果序列空了，就没必要继续了
  char root = pre[0];
  //取到前序序列的首字母，即根节点
  int k = inor.find(root);
  //找到中序序列中根节点的位置
  pre.erase(pre.begin());
  //删去前序序列中的根节点
  string leftpre = pre.substr(0, k);
  //从0开始切割k个
  string rightpre = pre.substr(k);
  //从k开始切割到最后
  string leftinor = inor.substr(0, k);
  //从0开始切割k个
  string rightinor = inor.substr(k + 1);
  //从k+1开始切割到最后
  work(leftpre, leftinor);
  work(rightpre, rightinor);
  printf("%c", root);
  //因为要输出后序序列，所以是左右根
  //先遍历左子树，再右子树，再根节点
}
int main() {
  freopen("data.in", "r", stdin);

  cin >> inor >> pre;
  work(pre, inor);
  // putchar('\n');
  return 0;
}