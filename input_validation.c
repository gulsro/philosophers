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

//checks if simulation can start with given time values for each state
static int     check_timing_possible(t_diner *diner)
{
        if (diner->number_of_philosophers < 1)
                return (0);
        if (diner->time_to_die < diner->time_to_eat || diner->time_to_die < diner->time_to_sleep)
                return (0);
}

//this funtion checks final input validation
int check_arguments_valid(t_diner *diner, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (check_all_digit(argv) == 0)
        {
                printf("One or more given arguments are in wrong format.");
		return (0);
	}
	init_arguments(diner, argc, argv);
	if (check_timing_possible(diner) == 0)
	{
		printf("Operation is not possible with given input.\n");
		return (0);
	}
	
}
