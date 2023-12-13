#include "shell.h"

/**
 * main - Input piont to the program
 * @argc: The integral values of the number of cmd_line arguments
 * @argv: An array of pointers that store the cmd_line arguments
 * Return: Alway 0
 */
int main(int argc, char **argv)
{
	const char *filename;

	count = 0,
	      status = 0;
	num_p = 0;

	if (setup_signal_catcher() < 0)
	{
		deallocate_env();
		return (-1);
	}
	initialize_aliases_count();
	if (isatty(STDIN_FILENO))
	{
		display_prompt();
		get_process_stdininput();
	}
	else
		if (argc == 2 && argv[1] != NULL)
		{
			filename = argv[1];
			if (validate_file(filename))
				ma_readprocess_execute_file(filename, argv[1]);
			else
				ma_perrorfile(argv[1]);
		}
	deallocate_env();
	return (0);
}