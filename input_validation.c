#include "philo.h"

static	int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

//this function checks if each character in the argument is a digit. it checks char by char so you dont need to check '-' in ft_atoi 
static int	check_all_digit(char **argv)
{
	int	i_argv;
	int	i;

	i_argv = 1;
	while (argv[i_argv])
	{
		i = 0;
		while (argv[i_argv][i])
		{
			if (ft_isdigit(argv[i_argv][i]) == 1)
				i++;
			else
				return (0);
		}
		i_argv++;
	}
	return (1);
}

//this funtion checks final input validation
int check_arguments_valid(int argc, char **argv)
{
	if (argv != 5)
		return (0);
	if (check_all_digit(argv) == 0)
		return (0);
}


