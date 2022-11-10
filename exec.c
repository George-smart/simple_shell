#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"
/**
 * launcher - takes a list of arguments
 * and forks the current process
 * @args: the list of arguments
 *
 * Return: 1 on failure
 */



int launcher(char **args, char **env)
{
	pid_t pid, wpid;
	int status;

	if (strcmp(args[0], "exit") == 0)
		return (0);

	pid = fork();
	if (pid == 0)
	{/* Child process */
		if (execve(args[0], args, env) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	} else if (pid < 0)
		perror("Error forking");/* Error forking */
	else
	{
		do {/* Parent process */
			wpid = waitpid(pid, &status, WUNTRACED);
			printf("%d\n",wpid);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}


/**
 * executor - work in progress
 *
 * @args: array of arguments
 *
 * Return: 1 on failure
 */


int executor(char **args, char **env)
{
	/* int i; */

	if (args[0] == NULL)
	{
		/* An empty command was entered. */
		printf("An empty command was entered.\n");
		return (1);
	}
	/*
	 *  for (i = 0; i < lsh_num_builtins(); i++) {
	 *    if (strcmp(args[0], builtin_str[i]) == 0) {
	 *      return (*builtin_func[i])(args);
	 *   }
	 *  }
	 */
	return (launcher(args, env));
}
