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
			case 'b':	// ������ �ּ� ���� 
				pointer_addr += 0x1;
				break;
			case 'u':	// ������ �ּ� ����
				pointer_addr -= 0x1;
				break;
			case 'l':	// ������ �� ����
				pointer_value[pointer_addr] += 1;
				break;
			case 'o':	// ������ �� ����
				pointer_value[pointer_addr] -= 1;
				break;
			case 'r':	// ������ ���� �ƽ�Ű ���� ���
				printf("%c\n", (int)pointer_value[pointer_addr]);
				break;
			case 'i':	// �����Ϳ� �ƽ�Ű ���� �Է�
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

	//�ٸ� ���ڰ��� ���� ó�� �ڵ� �߰� ����
}