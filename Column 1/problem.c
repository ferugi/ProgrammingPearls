#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bittools.h"

uint8_t mask[8];
FILE *fp;

void generate_random_ints(char* filename, uint8_t amount) {
	rand();
	for (int i = 0; i < 64; i ++)
	{

	}
}

int main() {
	for (int i = 0; i < 64; i++) {
		printf("bit %u is %u \n", i, get_bit(i, mask));
	}

	fp = fopen("C:\\Users\\Ferugi\\Documents\\ProgrammingPearls\\Column 1\\test.txt", "w+");
	fprintf(fp, "This is a test of fprintf... \n");
	fputs("This is a test of fputs...", fp);
	fclose(fp);
}