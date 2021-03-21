#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
int n, heap[maxn], size = 0;
void up(int p) //二叉小根堆向上调整（子节点小于父节点就调整）
{
  while (p > 1) {
    if (heap[p] < heap[p / 2]) {
      swap(heap[p], heap[p / 2]);
      p /= 2;
    } else
      break;
  }
}
void insert(int val) //二叉堆插入，新元素放在堆底，向上调整
{
  heap[++size] = val;
  up(size);
}
void down(int p) //二叉小根堆向下调整
{
  int s = p * 2;
  while (s <= size) { //下面这句话是从左右儿子中选一个更小的做交换
    if (s < size && heap[s + 1] < heap[s])
      s++;
    if (heap[s] < heap[p]) {
      swap(heap[s], heap[p]);
      p = s;
      s = p * 2;
    } else
      break;
  }
}
void extract() //二叉堆删除堆顶
{
  heap[1] = heap[size--]; //将堆底移至堆顶，向下调整
  down(1);
}
int gettop() //返回堆顶的值
{
  return heap[1];
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    insert(a); //建立二叉堆
  }
  long long ans = 0; //其实这里不会越界，但好像原题数据是3万
  while (size >= 2)  //如果还可合并
  {
    int top1 = gettop(); //取出堆顶（堆中最小值）后删除堆顶
    extract();
    int top2 = gettop(); //同上
    extract();
    ans += (top1 + top2);
    insert(top1 + top2); //将两数之和加入二叉堆，重复运算
  }
  cout << ans << endl; //输出答案
  return 0;
}