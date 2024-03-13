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

void Test_Point(){

  return;
}
