#include "main.h"

/**
 * exit_handling - handles the exit command
 * @arguments: pointer to array of arguments to exit command (char **)
 * Return: 0 if successful, otherwise 1
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int exit_handling(char **arguments)
{
	int exit_code = _atoi(arguments[1]);
	int check = check_exit_arg(arguments[1]);

	free_args(arguments);
	if (check == -1)
	{
		_enviornmnt(NULL, 0);
		_alias(NULL, 0);
		buffers(NULL, NULL, 0);
		exit(State);
	}
	else if (check == 2)
	{
		return (check);
	}
	else
	{
		_enviornmnt(NULL, 0);
		_alias(NULL, 0);
		buffers(NULL, NULL, 0);
		exit(exit_code);
	}
}
/**
 * check_exit_arg - checks if the argument of exit is valid
 * @str: pointer to argument of exit command (char *)
 * Return: 0 if valid, otherwise 2
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int check_exit_arg(char *str)
{
	int i;

	if (!str || (str && !str[0]))
	{
		return (-1);
	}
	else
	{
		for (i = 0; str[i]; i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				char error[1024];

				_strcpy(error, "./hsh: 1: exit: Illegal number: ");
				_strcpy(error + _strlen(error), str);
				_strcpy(error + _strlen(error), "\n");
				print(STDERR_FILENO, error, NULL);
				return (2);
			}
		}
	}
	return (0);
}
