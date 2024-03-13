#include "Tests.h"

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
