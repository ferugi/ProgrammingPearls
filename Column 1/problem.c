#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "bittools.h"
#include "filetools.h"

void generate_unordered_ints(uint32_t amount, FILE* output_file)
{
	rewind(output_file);

	uint32_t values[amount];
	memset(values, 0, amount*sizeof(uint32_t));

	for (int i = 0; i < amount; i++) 
	{
		values[i] = i + 1;
	}

	// Swap around values
	for (int i = 0; i < amount; i++) 
	{
		uint32_t random_value = rand() % amount;
		uint32_t holder = values[i];
		values[i] = values[random_value];
		values[random_value] = holder;
	}

	for (int i = 0; i < amount; i ++)
	{
		fprintf(output_file, "%u\n", values[i]);
	}

	rewind(output_file);
}

int main() 
{
	// Open input file
	FILE *file = fopen("C:\\Users\\Ferugi\\Documents\\ProgrammingPearls\\Column 1\\unorderedints.txt", "r");
	FILE *ordered_file = fopen("C:\\Users\\Ferugi\\Documents\\ProgrammingPearls\\Column 1\\orderedints.txt", "w+");
	
	uint32_t file_line_count = get_line_count(file);
	uint32_t file_max_int = get_max_int(file);

	printf("File is %u lines, the max integer is %u \n", file_line_count, file_max_int );

	uint8_t mask[file_max_int];
	memset(mask, 0, file_max_int*sizeof(uint8_t));

	//Read and set the bits in the file
	while (!feof(file)) {
		uint32_t current_value;
		fscanf(file, "%u\n", &current_value);
		set_bit(current_value, 1, mask);
	}

	// Generate ordered file
	for (int i = 1; i <= file_max_int; i++) {
		if (get_bit(i, mask))
		{
			fprintf(ordered_file, "%u\n", i);
		}
	}

	// Close files
	fclose(file);
	fclose(ordered_file);
}