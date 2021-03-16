#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//记录数组，输出数组
int book[30], n, print[30], ans;
bool ss[50];       //质数判断表，当然您打表也是可以的
void dfs(int step) //核心
{
  if (step == n) //搜索终点
  {
    if (ss[print[1] + print[n]]) //如果搜到目标状态
    {
      for (int i = 1; i < n; i++)
        printf("%d ", print[i]); //输出
      printf("%d\n", print[n]);  //防空格，窝就是被这个坑了好多次
    }
    return; //返回
  }
  for (int i = 2; i <= n; i++) //还未达到终点，继续搜索
  {
    if (ss[i + print[step]] && !book[i]) //判断搜索条件
    {
      book[i] = 1; //标记
      print[step + 1] = i;
      dfs(step + 1); //继续往下搜索
      book[i] = 0;   //回溯
    }
  }
  return; //好习惯
}
int main() {
  freopen("data.in", "r", stdin);
  ss[2] = 1;
  for (int i = 3; i < 32; i += 2) //生成质数表
  {
    bool f = true;
    for (int j = 3; j <= sqrt(i); j += 2)
      if (i % j == 0) {
        f = false;
        break;
      }
    if (f)
      ss[i] = 1;
  }
  while (scanf("%d", &n) != EOF) {
    if (ans)
      puts(""); //从第二个答案开始，多输出一个换行符
    ans++;
    printf("Case %d:\n", ans);
    print[1] = 1;
    memset(book, 0, sizeof(book));
    book[1] = 1;
    dfs(1);
  }
  return 0;
}