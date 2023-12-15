#include "main.h"

/**
 * handle_comm - handles the command
 * @command: pointer to command
 * Return: void
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
void handle_comm(char *command)
{
	char *first_sigment = _strtok2(command, " \t");
	char **arguments = NULL;

	add_arguments(&arguments, first_sigment);
	while (first_sigment != NULL)
	{
		char *cur_sigment = _strtok2(NULL, " ");

		if (cur_sigment == NULL)
		{
			break;
		}
		else
		{
			char c = check_many_comm(cur_sigment);

			if (c)
			{
				if (hand_comm_hlp(first_sigment, arguments, c))
					return;
				arguments = NULL;
				first_sigment = _strtok2(NULL, " ");
				if (!first_sigment)
					return;
				add_arguments(&arguments, first_sigment);
			}
			else
			{
				add_arguments(&arguments, cur_sigment);
			}
		}
	}
	hand_curr_comm(first_sigment, arguments);
}
/**
 * hand_comm_hlp - handles the command
 * @first_sigment: pointer to first sigment of command
 * @arguments: pointer to array of arguments
 * @c: char
 * Return: 1 if successful, otherwise 0
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int hand_comm_hlp(char *first_sigment, char **arguments, char c)
{
	switch (c)
	{
	case ';':
		hand_curr_comm(first_sigment, arguments);
		break;
	case '&':
		hand_curr_comm(first_sigment, arguments);
		if (State != 0)
			return (1);
		break;
	case '|':
		hand_curr_comm(first_sigment, arguments);
		if (!State)
			return (1);
		break;
	default:
		break;
	}
	return (0);
}
/**
 *  check_many_comm - checks if the user entered many commands
 * @str: pointer to string
 * Return: ';' if the user entered many commands, otherwise 0
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */

char check_many_comm(char *str)
{
	if (_strcmp(str, ";") == 0)
	{
		return (';');
	}
	else if (_strcmp(str, "&&") == 0)
	{
		return ('&');
	}
	else if (_strcmp(str, "||") == 0)
	{
		return ('|');
	}
	return (0);
}

/**
 * hand_curr_comm - handles the current command
 * @first_sigment: pointer to first sigment of command
 * @arguments: pointer to array of arguments
 * Return: void
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
void hand_curr_comm(char *first_sigment, char **arguments)
{
	char *c_path;

	if (_strchr(first_sigment, '/') && access(first_sigment, X_OK) == 0)
	{
		c_path = first_sigment;
		handle_execu(c_path, arguments);
		if (State)
			_state(2);
	}
	else if (check_built_in(first_sigment))
	{
		_state(hand_builtin(first_sigment, arguments));
	}
	else
	{
		char *path = gets_path(Environment);

		c_path = find_paths(path, first_sigment);
		if (c_path)
		{
			handle_execu(c_path, arguments);
			_Free(c_path);
		}
		else
		{
			_state(handle_error(first_sigment, path));
			arguments_free(arguments);
		}
	}
}
