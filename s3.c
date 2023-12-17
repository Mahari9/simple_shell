#include "shel.h"

/**
 * ma_itoa - Function that converts integer to string
 * @num: num to be  converted to string
 *
 * Return: pointer to converted string
 */
char *ma_itoa(int num)
{
	int rev_index, num_digits = 0;
	char *str;

	num_digits = count_digits(num);
	str = (char*)malloc((num_digits + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	while (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	rev_index = num_digits - 1;
	while (num > 0)
	{
		str[rev_index] = '0' + (num % 10);
		num /= 10;
		rev_index--;
	}
	str[num_digits] = '\0';

	return (str);
}

/**
 * count_digits - Function that determine the number of digits of integer
 * @num: given integer to be determined it's number of digits
 * Return: number of digits in the integer
 */
int count_digits(int num)
{
	int remain = num, num_digits = 0;

	if (num == 0)
		num_digits = 1;
	while (remain != 0)
	{
		num_digits++;
		remain /= 10;
	}
	return (num_digits);
}

/**
* ma_puts - Function that write output of characters and strings
* @cos: character or string  to be written
* Return: 1 on success
*/
int ma_puts(char *cos)
{
	while (*cos != '\0')
	{
		write(1, cos, 1);
		cos++;
	}
	return (1);
}

/**
 * ma_strchr - custom version of the strchr function
 * @s: string which may contain character
 * @crt: character to be searched inside the string
 *
 * Return: pointer to the first occurance of crt or NULL
*/

char *ma_strchr(const char *s, int crt)
{
	for (; *s != '\0'; s++)
	{
		if (*s == crt)
		{
			return ((char *)s); /* crt is Found in the string */
		}

	} /* crt is not found in the string */
	return (NULL);
}
