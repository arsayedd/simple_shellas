#include "main.h"

/**
 * _atoi - changes a string to an integer
 * @string: string to convert
 * Return: integer
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int _atoi(char *string)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	while (string && string[i])
	{
		if (string[i] == '-')
		{
			sign *= -1;
		}
		else if (string[i] >= '0' && string[i] <= '9')
		{
			res = (res * 10) + (string[i] - '0');
		}
		else
		{
			break;
		}
		i++;
	}
	return (res * sign);
}
/**
 * nts - transform a number into a string
 * @num: number to transform
 * @result: buffer for storing the result
 * Return: void
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
void nts(int num, char result[])
{
	int index = 0;

	nts_recursive_helper(num, result, &index);

	result[index] = '\0';
}

/**
 * nts_recursive_helper - transform a number into a string
 * @num: number to transform
 * @result: buffer for storing the result
 * @index: index of the buffer
 * Return: void
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
void nts_recursive_helper(int num, char result[], int *index)
{
	if (num < 0)
	{
		result[(*index)++] = '-';
		num = -num;
	}

	if (num / 10 != 0)
	{
		nts_recursive_helper(num / 10, result, index);
	}

	result[(*index)++] = num % 10 + '0';
}
