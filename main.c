#include <stdio.h>
#include <float.h>
#include <stdbool.h>  // bool 作为 _Bool 的别名
#include <stdlib.h>
#include <ctype.h>  // 测试字符串是否符合要求


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
void Test_Point_Const();

int main(){
	return 0;
}

void Test_Standard_io_Stream() {
	/*
	* 测试gets(),fgets(),puts(),fputs()函数
	* 一般gets与puts搭配；fgets与fputs搭配，常用于文件读写
	*/

	  char cs[CHARS_NUM] = { 0 };
	  
	  printf("Now Test gets() function:\n");
	  gets(cs);  // 将不会检查输入是否会导致溢出，不安全；不会存储换行符号
	  puts(cs);  // 输出时会自动产生一个换行符
	  
	  printf("Now Test fgets() function:\n");
	  fgets(cs, CHARS_NUM, stdin); // 会接受CHARS_NUM - 1个字符，或者遇到回车符号；会存储换行符号；格式化输入
	  fputs(cs, stdout);  // 输出时不会自带换行符
	  
	  /* 如果要清除输入时的残留字符，针对于格式化输入，请使用以下参考代码
	  * while(getchar() != '\n')
	  *		continue;
	  */
	  
	  printf("Now Test End.");
	  return;
}

void Mix_GetC_Scanf() {
	/* 
		针对getchar与scanf获取字符流输入问题
		使用特性不同导致混用有一定难度
	*/
	int ch;
	int a, b;

	while ((ch = getchar()) != '\n') {
		if (scanf_s("%d %d", &a, &b) == 2) {
			printf("%c %d %d\n", ch, a, b);
		}
		else {
			printf("warning, you cannot do this.Try again.\n");
		}
		
		while (getchar() != '\n');  // 过滤多余的字符
	}
}

void Test_Bool() {
	int num;
	bool Test = scanf("%d", &num);
	bool Test1 = true;  // or false

	printf("%d", Test);
}

void Test_Float() {
	float a = 1.0 / 3.0;
	double b = 1.0 / 3.0;

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

void Test_Point_Const(const int array_outer[]){  // 此处的形参表明array_outer是个指针，同时提醒程序员一般是数组传入
	int array[CHARS_NUM] = { 0 };
	int* p7 = (int [5]){1, 2, 3, 4, 5};  // 复合字面量，类似于2，‘Y’等常量，不过其作用域为块作用域
	
	int* p1 = array;  // 大部分情况下两者使用共通

	int array1[CHARS_NUM][CHARS_NUM] = { 0 };
	int*p2 = array1; // 赋值不可取
	p2 = array1[0]; // 有效
	
	int**pp1 = array1;  // 该赋值也有问题
	*pp1 = array1[0];  // 没问题
	
	int (*p3)[CHARS_NUM] = array1;  // 该赋值没问题，这是由单个指针构成，一次指向CHARS_NUM个数据
	int *p4[CHARS_NUM] = array1;  // 注意两者区别，这是由指针构成的数组

	// 注意：不要对多层引用加上const限定符，可能导致意外的结果
	const int **pp2;
	int *p5;
	const int n = 13;
	pp2 = &p5;
	*pp2 = &n;
	*p5 = 10;

	const int const *p6 = p1;  // 不可更改值，也不能指向其余的地方；相应的const对应相应的要求

	
	return;
}
