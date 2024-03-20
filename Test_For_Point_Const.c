#include "Tests.h"

#define CHARS_NUM 20


void Test_Point_Const(const int array_outer[]){  // 此处的形参表明array_outer是个指针，同时提醒程序员一般是数组传入
	int array[CHARS_NUM] = {[CHARS_NUM - 3 = 9};  // C99
		
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

	int* p7 = (int [5]){1, 2, 3, 4, 5};  // 复合字面量，类似于2，‘Y’等常量，不过其作用域为块作用域

	int (*p8)[CHARS_NUM] = (int [2][CHARS_NUM]){ 0 };  // 一个指针
	int *p9[CHARS_NUM];  // CHARS_NUM个指针构成的数组
	
	return;
}
