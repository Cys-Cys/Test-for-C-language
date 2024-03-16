#include "Tests.h"

void Dynamic_Test_1(){
  int n = 9;
  int m = 3;

  int Array[n][m] = { 0 };  // 动态数组，n。m为变量，但是在数组创建时会固定

  int *p1;
  p1 = (int*) malloc(sizeof(int) * n * m);  // 动态堆区赋值，比上述情况更加灵活
  free(p1);

  Dynamic_Test_2(n, m. Array);

  return;
}

void Dynamic_Test_2(int n, int m, int Array[n][m]){
  // 子函数调用时维度值一定先于动态数组确定
  return;
}
