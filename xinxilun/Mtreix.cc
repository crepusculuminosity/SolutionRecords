#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void printMessage();
int main() {
  int r, s, i, j, k = 0;
  double p[20]; //存放输入信源概率矩阵
  double z[20];
  double q[20][20]; //存放信道转移概率矩阵
  double F[20][20]; //存放(|)iipxy的概率分布矩阵的转置
  double x, y, a;
  double epsilon = 1e-5; //门限
  double C = -1000.0; //取初始迭代时的信道容量为一个较大的负数
  printMessage();
  printf("!-------请输入信源符号个数:---------!\n");
  scanf("%d", &r);
  printf("!-------请输入信宿符号个数：---------!\n");
  scanf("%d", &s);
  printf("!-------请输入信道转移概率矩阵---------!\n\n");

  for (i = 0; i < r; i++) {
    for (j = 0; j < s; j++)
      scanf("%lf", &q[i][j]);
    printf("\n");
  }

  for (i = 0; i < r; i++)
    p[i] = (double)(1.0 / (double)r);
  //设初始信源分布为等概分布
  do {
    k++;
    a = C;
    for (j = 0; j < s; j++) {
      x = 0.0;
      for (i = 0; i < r; i++)
        x = x + (p[i]) * (q[i][j]); // x 为(|)iipxy的分母部分
      if (x > 0)
        for (i = 0; i < r; i++)
          F[i][j] = (p[i]) * (q[i][j]) / x; // F为(|)iipxy的概率分布矩阵的转置
      else
        for (i = 0; i < r; i++)
          F[i][j] = 0.0; //(|)iipxy的分母部分为0时，令F=0
    }
    y = 0.0;
    for (i = 0; i < r; i++) {
      z[i] = 0.0;
      for (j = 0; j < s; j++) {
        if (F[i][j] > 0)
          z[i] = z[i] +
                 (q[i][j] * (log(F[i][j]) / log(2.0))); // z[i]为ip的分子部分
      }
      z[i] = (pow(2.0, z[i]));
      y = y + z[i]; // z[i]为ip的分母部分
    }
    for (i = 0; i < r; i++) {
      p[i] = z[i] / y; //更新输入信源概率矩阵
    }
    C = (log(y) / log(2.0)); //求信道容量单位为“bit”
  } while (fabs((C - a) / C) > epsilon);
  printf("!----------迭代次数为:k=%d  --------!\n", k); //输出迭代次数
  printf("!----------最佳信源分布为：--------!\n\n");
  for (i = 0; i < r; i++) {
    printf("%.3lf", p[i]); //输出信源的最佳分布，保留3位小数
  }
  printf("\n");
  printf("!----------信道容量为:C=%.3lf bit --------!\n\n",
         C); //输出信道容量，保留3位小数
  getchar();
  getchar();
}
void printMessage() {
  printf("!---------                --------!\n\n");
  printf("!----------姓名：小猪嘎嘎     --------!\n\n");
  printf("!----------信道容量迭代算法 --------!\n\n");
  printf("!----------csdn   --------!\n\n");
}