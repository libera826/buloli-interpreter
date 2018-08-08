/*
Copyright(c) 2018 libera826

See the file license.txt for copying permission.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char parse_CMD_line(int argc);

FILE *source_file;
unsigned char pointer_addr = 0;
char pointer_value[256] = { 0, };

int main(int argc, char *argv[]) {

	if (!parse_CMD_line(argv)) {
		return 1;
	}
 
	// Read code from file
	source_file = fopen(argv[1], "r");
	if (source_file == NULL) {
		printf("FILE OPEN ERROR\n");
		return 1;
	}
	
	// Interpret code
	while (!feof(source_file)) {	// check EOF 
		printf("===========DEBUG INFO===========\n");
		printf("pointer = 0x%02x\n", pointer_addr);
		printf("*pointer = 0x%02x\n", pointer_value[pointer_addr]);
		printf("================================\n");
		switch (fgetc(source_file)) {
			case 'b':	// 포인터 주소 증가 
				pointer_addr += 0x1;
				break;
			case 'u':	// 포인터 주소 감소
				pointer_addr -= 0x1;
				break;
			case 'l':	// 포인터 값 증가
				pointer_value[pointer_addr] += 1;
				break;
			case 'o':	// 포인터 값 감소
				pointer_value[pointer_addr] -= 1;
				break;
			case 'r':	// 포인터 값의 아스키 문자 출력
				printf("%c\n", (int)pointer_value[pointer_addr]);
				break;
			case 'i':	// 포인터에 아스키 문자 입력
				scanf("%c", &pointer_value[pointer_addr]);
				break;
			default:
				break;
		}
	}
	fclose(source_file);

	return 0;
}

char parse_CMD_line(int argc) {
	if (argc <= 1) {
		printf("buloli <-d> <file name>\n");
		return -1;
	}

	//다른 인자값에 대한 처리 코드 추가 에정
}