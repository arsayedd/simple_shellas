#include "main.h"

/**
 * pt_all_alias - print all alias
 *
 * Return: 0 on success, 1 on failure
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int pt_all_alias(void)
{
	int i = 0;
	char **alias_lisr = Alias_list;

	if (alias_lisr)
		while (alias_lisr[i])
		{
			char *str = _strdup(alias_lisr[i]);
			char *ptr = _strstr(str, "=");
			*ptr = '\0';
			print(STDOUT_FILENO, str, "='", ptr + 1, "'\n", NULL);
			_Free(str);
			i++;
		}
	return (0);
}
