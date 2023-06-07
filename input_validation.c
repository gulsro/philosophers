#include "philo.h"

static	int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

//This function checks if each character in the argument is a digit. it checks char by char so you dont need to check '-' in ft_atoi 
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

// Initializes command line arguments, will be called in check_arguments_valid() right after input validation
void    init_arguments(t_diner *diner, int argc, char **argv)
{
    diner->number_of_philosophers = ft_atoi(argv[1]);
    diner->time_to_die = ft_atoi(argv[2]);
    diner->time_to_eat = ft_atoi(argv[3]);
    diner->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        diner->must_eat = ft_atoi(argv[5]);
}


//This funtion checks if given arguments are digit, is so, inits arguments
int check_validation_and_init_arguments(t_diner *diner, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (check_all_digit(argv) == 0)
	{
		print_error("One or more given arguments are in wrong format.");
		return (0);
	}
	init_arguments(diner, argc, argv);
	if (diner->number_of_philosophers < 1)
	{
		return (0);
	}
	return (1);	
}
