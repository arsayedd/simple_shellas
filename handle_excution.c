#include "main.h"
/**
 * handle_execu - handles the excution of command
 * @c_path: pointer to path of command
 * @argumnet: pointer to array of arguments
 * Return: 0 if successful, otherwise 1
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int handle_execu(char *c_path, char **argumnet)
{
	int pid = fork();

	if (pid == 0)
	{
		int state = execute_comm(c_path, argumnet);

		if (state == -1)
		{
			printf("exError\n");
		}
		return (state);
	}
	else
	{
		int exit_code;

		wait(&exit_code);
		free_args(argumnet);
		if (exit_code)
			_state(2);
		else
			_state(exit_code);
		return (exit_code);
	}
}
/**
 * execute_comm - executes the command
 * @path: pointer to path of command
 * @args: pointer to array of arguments
 * Return: 0 if successful, otherwise 1
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int execute_comm(char *path, char **args)
{
	execve(path, args, Environment);

	exit(2);
}
/**
 * errors_handling - handles the error
 * @first_sigment: pointer to first sigment of command
 * @path: pointer to path of command
 * Return: 0 if successful, otherwise 1
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int errors_handling(char *first_sigment, char *path)
{
	char error[1024];

	_strcpy(error, "./hsh: line 1: ");
	if (!Environment[1] || !*Environment[1] ||
		_strstr(Environment[1], "_=") == Environment[1] ||
		!_strchr(Environment[1], '=') || _strlen((char *)Environment) < 5)
	{
		_strcpy(error, "./hsh: 1: ");
		_strcpy(error + _strlen(error), first_sigment);
		print(STDERR_FILENO, error, ": not found\n", NULL);
		return (127);
	}
	_strcpy(error + _strlen(error), first_sigment);
	print(STDERR_FILENO, error, NULL);
	if ((!_strchr(first_sigment, '\\') && path && path[0]) || !path)
	{
		char *error = ": command not found\n";

		print(STDERR_FILENO, error, NULL);
	}
	else
	{
		char *error = ": No such file or directory\n";

		print(STDERR_FILENO, error, NULL);
	}
	return (127);
}
