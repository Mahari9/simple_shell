#include "shell.h"

/**
 * ma_realloc - reallocates a memory block
 * @ptr: pointer
 * @old_size: previous size of the pointer
 * @new_size: new size of the pointer
 * Return: Pointer to the reallocated memory
 */
void *ma_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;
	char *old_ptr, *new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		result = malloc(new_size);
		if (result == NULL)
		return (result);
	}
	if (new_size == 0 && ptr)
	{
		free(ptr);
	}
	old_ptr = ptr;
	result = malloc(sizeof(*old_ptr) * new_size);
	if (result == NULL)
		free(ptr);
	new_ptr = result;
	for (i = 0; i < old_size && i < new_size; i++)
		result = *old_ptr++;
	free(ptr);
	return (result);
}

/**
 * ma_memcpy - copy n bytes of memory from src to dst
 * @dst: destination pointer
 * @src: source pointer
 * @n: the size in bytes to be copied
 * Return: pointer to new pointer
 */
char *ma_memcpy(char *dst, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dst[i] = src[i];
	}
	return (dst);
}
/**
 * deallocate - free allocated memory for array pointer and user input
 * @argus: array of pointer to the character
 * @usrin: pointer to character
 */
void deallocate(char **argus, char *usrin)
{
	free(argus);
	free(usrin);
	argus = NULL;
	usrin = NULL;
}

/**
 * deallocate_env - deallocate memory allocated for ma_setenv
 */
void deallocate_env(void)
{
	int i;

	for (i = 0; i < num_p && env_n[i] != NULL; ++i)
		free(env_n[i]);
}
