#include "main.h"
/**
 * _strchr - finds a character in a string
 * @str: pointer to string
 * @c: character to locate
 * Return: pointer to first occurrence of character in string
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int *_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (!*str)
		{
			return (NULL);
		}
		str++;
	}
	return ((int *)str);
}
/**
 * _strtok - breaks down a string into tokens
 * @str: pointer to string
 * @delimiters: pointer to delimiters
 * Return: pointer to next token
 */
char *_strtok(char *str, const char *delimiters)
{
	static char *chank;
	char *ret;

	if (str)
		chank = str;
	else if (!*chank)
		return (NULL);

	ret = chank;

	while (*chank && !_strchr(delimiters, *chank))
		chank++;

	if (*chank)
		*chank++ = '\0';

	return (ret);
}
/**
 * _strtok2 - breaks down a string into tokens
 * @str: pointer to string
 * @delimiters: pointer to delimiters
 * Return: pointer to next token
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
char *_strtok2(char *str, const char *delimiters)
{
	static char *chank;
	char *ret;

	if (str)
		chank = str;
	else if (!*chank)
		return (NULL);

	ret = chank;

	while (*chank && !_strchr(delimiters, *chank))
		chank++;

	if (*chank)
		*chank++ = '\0';

	return (ret);
}
/**
 * _strlen - determines the length of a string
 * @p_string: pointer to string
 * Return: length of string
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int _strlen(char *p_string)
{
	size_t i = 0;

	while (p_string && p_string[i] != '\0')
		i++;
	return (i);
}
/**
 * _strdup - provides a pointer to a newly allocated space in memory
 * @p_string: pointer to string
 * Return: pointer to new string
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
char *_strdup(char *p_string)
{
	size_t i = 0;
	char *str;
	int len;

	if (p_string == NULL)
		return (NULL);

	len = _strlen(p_string);
	str = _malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);

	while (p_string[i] != '\0')
	{
		str[i] = p_string[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
