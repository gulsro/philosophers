#include "philo.h"

//number_of_philosophers~~time_to_die~~time_to_eat~~time_to_sleep
void	init_args(t_diner *diner, int argc, char **argv)
{
	diner->number_of_philosophers = ft_atoi(argv[1]);
	diner->time_to_die = ft_atoi(argv[2]);
	diner->time_to_eat = ft_atoi(argv[3]);
	diner->time_to_sleep = ft_atoi(argv[4]);
}


