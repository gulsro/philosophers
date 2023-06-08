#include "philo.h"

//number_of_philosophers~~time_to_die~~time_to_eat~~time_to_sleep
int main(int argc, char **argv)
{
	t_diner	*diner;

	diner = malloc(sizeof(t_diner));
	if (!diner)
		return (0);
	if (check_validation_and_init_arguments(diner, argc, argv) == 0) //check error msgs
	{
		free(diner);
		return (0);
	}
	init_threads_mutex_philo(diner);
	return (0);
}
