#include <stdio.h>
#include <float.h>
#include <stdbool.h>  // bool 作为 _Bool 的别名
#include <stdlib.h>
#include <ctype.h>  // 测试字符串是否符合要求
#include "Tests.h"


// #define Q "Hello"
#define Q "\"Hello\""
// #define ( {	不可取
#define CHARS_NUM 80

const int alxy = 50000;  // 具有外部链接的文件作用域的静态变量
static const int dieqi = 100000;  // 具有内部链接的文件作用域的静态变量

void Test_Float();
void Test_Bool();
void Mix_GetC_Scanf();
void Test_Standard_io_Stream();
void Test_Num();

int main(int argc, char * argv[]){

	printf("We are running %s",argv[0]);  // 一般来说，argv第一个字符串应该是本运行程序文件名称
	return 0;
}

void Test_Bool() {
	int num;
	bool Test = scanf("%d", &num);
	bool Test1 = true;  // or false

	printf("%d", Test);

	return;
}

void Test_Float() {
	float a = 1.0 / 3.0;
	double b = 1.0 / 3.0;

	// 当显示位数不同时，float和double精度差异就产生了
	printf("%-20.6f %-20.6f\n", a, b);
	printf("%-20.12f %-20.12f\n", a, b);
	printf("%-20.16f %-20.16f\n", a, b);
	printf("%-20d %-20d\n",FLT_DIG, DBL_DIG);  // 测试float和double的字节数

  	return;
}

void Test_Num()
{
	float a = 3.33;
	unsigned long long s = 1;
	
	printf("%s\n", Q);  // 输出带双引号的Q
	printf("test " Q  "test" "\n");  // 分段字符输出
	printf("%*.3f \n", 9, a);  // *号用于动态指定宽度设定
	printf("%llu \n", s);
	printf("%zd\n", sizeof(unsigned long long));

    	return;
}
