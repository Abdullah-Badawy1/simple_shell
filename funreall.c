#include "main.h"

/**
 * custom_memset - Fills memory with a constant byte.
 * @s: Pointer to the memory area.
 * @b: The byte to fill *s with.
 * @n: The amount of bytes to be filled.
 *
 * Return: A pointer to the memory area s.
 */
char *custom_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	do

	{
		s[i] = b;
		i++;
	} while (i < n);

	return (s);
}

/**
 * custom_free - Frees a string of strings.
 * @ptr: Pointer to memory to be freed.
 */
void custom_free(void *ptr)
{
	if (!ptr)
		return;

	free(ptr);
}

/**
 * custom_realloc - Reallocates a block of memory.
 * @ptr: Pointer to the previous malloc'ated block.
 * @old_size: Byte size of the previous block.
 * @new_size: Byte size of the new block.
 *
 * Return: Pointer to the old block.
 */
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;

	if (!ptr)
		return (malloc(new_size));

	if (!new_size)
		return (free(ptr), NULL);

	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;

	while (old_size--)
		((char *)p)[old_size] = ((char *)ptr)[old_size];

	free(ptr);
	return (p);
}
