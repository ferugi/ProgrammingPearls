#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "filetools.h"

int get_line_count(FILE* file)
{
	rewind(file);

	int line_count = 0;

	while (!feof(file))
	{
		if (fgetc(file) == '\n') 
		{
			line_count++;
		}
	}

	rewind(file);

	return line_count;
}

int get_max_int(FILE* file)
{
	rewind(file);

	int max_value = 0;
	int current_value = 0;

	while (!feof(file))
	{
		fscanf(file, "%u\n", &current_value);
		if (current_value > max_value) 
		{
			max_value = current_value;
		}
	}

	rewind(file);

	return max_value;
}