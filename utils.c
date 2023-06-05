#include "philo.h"

int	ft_atoi(char *str)
{
	int				i;
	long long int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (n > INT_MAX)
	{
		printf("Number of the philos are greater than INT_MAX");
		return (0);
	}
	return ((int)(n));
}

// Initializes command line arguments, will be called in check_arguments_valid() right after input validation
void	init_arguments(t_diner *diner, int argc, char **argv)
{
	diner->number_of_philosophers = ft_atoi(argv[1]);
	diner->time_to_die = ft_atoi(argv[2]);
	diner->time_to_eat = ft_atoi(argv[3]);
	diner->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		diner->must_eat = ft_atoi(argv[5]);
}

//no need assign_forks anymore
/*
void	assign_forks(s_diner *diner)
{
	int	i;

	i = 0;
	diner->philo.left_fork_id = diner->philo.philo_id;
	diner->philo.right_fork_id = diner->philo.philo_id + 1;

}*/
