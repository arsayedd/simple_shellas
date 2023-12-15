#include "main.h"

/**
 * hand_env - handle env command (char **)
 * @envp: arguments to handle env command (char **)
 * Return: 0 on success, 1 on failure
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int hand_env(char *envp[])
{
	int i = 0;

	while (envp[i])
	{
		print(STDOUT_FILENO, envp[i], "\n", NULL);
		i++;
	}
	return (0);
}
/**
 * hand_unstenv - handle unsetenv command (char **)
 * @argv: arguments to handle unsetenv command (char **)
 * Return: 0 on success, 1 on failure
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int hand_unstenv(char *argv[])
{
	int i = 0, x = 0;
	char **env = Environment;

	if (env && argv[1])
		while (env[i])
		{
			if (_strstr(env[i], argv[1]) == env[i] && env[i][_strlen(argv[1])] == '=')
			{
				_Free(env[i]);
				env[i] = env[i + 1];
				x = i + 1;

				while (env[x])
				{
					env[x] = env[x + 1];
					x++;
				}
				free_args(argv);
				return (0);
			}
			i++;
		}
	free_args(argv);
	return (-1);
}

/**
 * hand_setenv - handle setenv command (char **)
 * @argv: arguments to handle setenv command (char **)
 * Return: 0 on success, 1 on failure
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
int hand_setenv(char *argv[])
{
	int i = 0;
	char *buffer = NULL;

	if (argv && argv[1] && argv[2])
	{
		buffer = _malloc(_strlen(argv[1]) + _strlen(argv[2]) + 2);
		_strcpy(buffer, argv[1]);
		_strcat(buffer, "=");
		_strcat(buffer, argv[2]);

		while (Environment[i] != NULL)
		{
			if (_strstr(Environment[i], argv[1]) == Environment[i] &&
				Environment[i][_strlen(argv[1])] == '=')
			{
				free(Environment[i]);
				Environment[i] = buffer;
				free_args(argv);
				return (0);
			}
			i++;
		}

		add_arguments(Environment_ptr, buffer);
		free_args(argv);
		buffer_free(buffer);
		_Free(buffer);
		return (0);
	}
	else
	{
		free_args(argv);
		return (2);
	}
}

/**
 * buffer_free - free buffer
 * @str: pointer to buffer
 * Return: void
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
void buffer_free(char *str)
{
	int i = 0;

	while (str[i])
	{
		str[i] = '\0';
	}
}
/**
 * get_envs_val - get env value
 * @key: key to get value of (char *)
 * Return: value of env (char *)
 * Authors: Ahmed Raafat & Ahmed Abdelanasser
 */
char *get_envs_val(char *key)
{
	char *path = NULL;
	char *cur_env = NULL;
	char *value = NULL;
	int i = 0;
	char **env_list = Environment;

	if (key && *key && env_list)
	{
		path = _strdup(key);
		path = _realloc(path, _strlen(path) + 2);
		_strcat(path, "=");

		while (env_list[i])
		{
			cur_env = env_list[i];
			if (_strstr(cur_env, path) == cur_env)
			{
				value = _strdup(cur_env + _strlen(path));
				_Free(path);
				return (value);
			}
			i++;
		}
	}
	_Free(path);
	return (value);
}
