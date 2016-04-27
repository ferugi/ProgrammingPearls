#include <stdint.h>
#include "bittools.h"

// Sets bits in a bit mask consisting of grouped bits. 
void set_bit(uint8_t bit_number, uint8_t value, uint8_t* bit_mask) 
{
	uint8_t length_of_group = sizeof(uint8_t);
	uint8_t bit_group_number = bit_number / length_of_group;
	uint8_t bit_internal_number = bit_number % length_of_group;
	uint8_t old_group = bit_mask[bit_group_number];

	uint8_t selection = 0x01 << bit_internal_number;

	if (value == 1) 
	{
		// Set bit # bit_number to 1 (true)
		bit_mask[bit_group_number] = old_group | selection;
	}
	else 
	{
		// Set bit # bit_number to 0 (false)
		selection = 0xff ^ selection;
		bit_mask[bit_group_number] = old_group & selection;
	}
}

// Gets the value of a bit from within a bit_mask
uint8_t get_bit(uint8_t bit_number, uint8_t* bit_mask)
{
	uint8_t length_of_group = sizeof(uint8_t);
	uint8_t bit_group_number = bit_number / length_of_group;
	uint8_t bit_internal_number = bit_number % length_of_group;

	uint8_t selection = 0x01 << bit_internal_number;
	uint8_t bit_value = (bit_mask[bit_group_number] & selection) >> bit_internal_number;

	return bit_value;
}