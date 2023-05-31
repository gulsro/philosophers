#include "philo.h"

//number_of_philosophers~~time_to_die~~time_to_eat~~time_to_sleep
int main(int argc, char **argv)
{
	t_diner	*diner;

	diner = malloc(sizeof(t_diner));
	if (!diner)
		return (1);
	if (check_arguments_valid(diner, argc, argv) == 0) //check error msgs
		return (1);
	init_philos(diner);
	init_mutexes(diner);
}
