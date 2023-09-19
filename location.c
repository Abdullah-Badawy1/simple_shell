#include "main.h"

/**
 * custom_bfree - Frees a pointer and NULLs the address.
 * @ptr: Address of the pointer to free.
 *
 * Return: 1 if freed, otherwise 0.
 */
int custom_bfree(void **ptr)
{
	return ((ptr && *ptr) ? (free(*ptr), (*ptr = NULL), 1) : 0);
}