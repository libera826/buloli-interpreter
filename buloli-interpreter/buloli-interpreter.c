/*
 * Copyright (c) 2018 libera826
 * See the file license.txt for copying permission.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

char parse_CMD_line(int argc, char *argv[]);

FILE *source_file;
char source_file_name[256];
unsigned char pointer_addr = 0;
char pointer_value[256] = { 0, };
char debug_mod = 0;

int main(int argc, char *argv[]) {

	if (!parse_CMD_line(argc, argv)) {
		return 1;
	}
 
	// Read code from file
	source_file = fopen(source_file_name, "r");
	if (source_file == NULL) {
		printf("FILE OPEN ERROR\n");
		return 1;
	}
	
	// Interpret code
	while (!feof(source_file)) {	// check EOF
		if (debug_mod == 1) {		// check debug mode
			printf("===========DEBUG INFO===========\n");
			printf("pointer = %#02x\n", pointer_addr);
			printf("*pointer = %#02x\n", pointer_value[pointer_addr]);
			printf("================================\n");
		} 
		
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
		}
	}
	fclose(source_file);
	
	return 0;
}

char parse_CMD_line(int argc, char *argv[]) {
	char curr_arg;
	extern char *optarg; // 지정 옵션 이외의 파라미터 값
	
	if (argc <= 1) {	//옵션이 입력 안됬거나 파일명이 없을경우
		printf("Option : \n");
		printf("\t-f [file_name] : Setting source file \n");
		printf("\t-d : Activating Debug Mode\n");
		return false;
	}

	while ((curr_arg = getopt(argc, argv, "df:")) != -1) {	// -1 means getopt() parse all options
		switch(curr_arg) {
			case 'f':
				strcpy(source_file_name, optarg);
				break;
			case 'd':
				debug_mod = 1;
				break;
			default:
				printf("Option : \n");
				printf("\t-f [file_name] : Setting source file \n");
				printf("\t-d : Activating Debug Mode\n");
				break;
		}
	}
	return true;
}