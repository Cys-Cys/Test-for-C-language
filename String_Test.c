#include "Test.h"
#include <string.h>

#define NUM 20

void Test_String_Fun(){
  /*
    字符串不同于基本数据类型，不鞥使用加减乘除。需要专门的函数
  */
  char str1[NUM] = "String";  // 字符串字面量最好不要修改。不知道内存含有一个副本还是多个副本
  char str2[NUM];

  // 复制值
  strcpy(str2, str1);  // 不会检查是否溢出，不行
  strncpy(str2, str1, NUM);

  //链接字符串 
  strcat(str2, str1);
  strncat(str2, str1. NUM);

  //比较
  strcmp(str2, str1);
  strncmp(str2, str1, 3);  // 比较指定值前的字符串

  strlen(str1);  // 字符串长度
  
  return;
}
