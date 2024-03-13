#include "Tests.h"

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

	return;
}
