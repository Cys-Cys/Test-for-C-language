#include "Tests.h"

#define CNTL_Z '\032'

void Test_File() {
	/*
		文件被C语言划分为文本模式与二进制模式
			文本模式下，本地环境会被映射成C语言模式；而二进制模式不会转换字符，例如\r\n不会被转换成\n
			C语言支持标准高级I/O
			C语言标准I/O会打开standard input，standard output和standard error；error会定向到屏幕输出，在文件输入时很方便
			C语言设置为输出输入均为缓冲模式
	*/

	FILE* fp;  // 单独设计的File文件类型
	char ch = 'A';
	char ch1[20] = {'\0'};
	long last = 0L;
	int num;
	fpos_t last2 = 5;

	// 打开文件,如果含有x则为独占模式
	if ((fp = fopen("Test_Files.txt", "w+")) == NULL) {
		fprintf(stderr,"Failure");
		exit(EXIT_FAILURE);
	}

	// 文件流输入
	fprintf(stdout, "Please Enter the chars in 20 Numbers:");

	if (fscanf(stdin, "%s", ch1) != 1) {
		fprintf(stderr, "No, Failure");
		exit(EXIT_FAILURE);
	}
	/*
	* fgets(ch1, 20, fp);
	*/
	fprintf(fp, "%s\n", ch1);

	while (ch <= 'Z') {
		// 文件流输出
		fprintf(fp, "This is the %c.\n", ch);
		ch++;
	}

	// 回转到开头，注：换行符,\0占一个字符
	rewind(fp);
	fgets(ch1, 20, fp);
	fputs(ch1, stdout);
	while (!feof(fp)) {  // 上一次调用到达文件尾部会返回非零值，没达到尾部返回0
		// ferror则是强调错误情况，出现错误返回非零值，没有返回0
		fgets(ch1, 20, fp);
		fputs(ch1, stdout);
	}

	rewind(fp);
	fseek(fp, 8L, SEEK_SET);  // 定位到想要的位置
	// fsetpos(fp, &last2);
	printf("THis is the NExt out:");
	fgets(ch1, 20, fp);  // fseek升级版
	fputs(ch1, stdout);

	last = ftell(fp);
	// fgetpos(fp, &last2);
	printf("last:%ld\n", last);

	fflush(stdin);
	// ungetc(ch, fp);  将ch放回缓冲区中，位置位于上一个输出字符的位置
	// setvbuf(fp, NULL, _IOBUF, 4096);  开辟4096字节的缓冲区

	rewind(fp);
	printf("The last enter:\n");
	if (scanf("%s", ch1) != 1) {
		printf("NO you cannot do this");
	}

	last2 = 200;
	fsetpos(fp, &last2);
	fwrite(ch1, sizeof(char) * strlen(ch1), 1, fp);
	rewind(fp);
	num = fread(ch1, sizeof(char), 19, fp);  // 读取char类型时不会插入'\0'
	ch1[19] = '\0';
	printf("fread number:%d\n", num);
	printf("fread:%s\n", ch1);

	if (fclose(fp) != 0)// 关闭文件
		fprintf(stderr, "ERROR TO CLOSE FILE,");

	return;
	// exit(EXIT_SUCCESS);
}
