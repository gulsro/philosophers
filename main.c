#include "philo.h"

//number_of_philosophers~~time_to_die~~time_to_eat~~time_to_sleep
int main(int argc, char **argv)
{
	t_philo	*philo;
	t_diner	*diner;
	if (check_arguments_valid(argc, argv) == 0) //check error msgs
		return (1);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	diner = malloc(sizeof(t_diner));
	if (!diner)
	{
		free(philo);
		return (1);
	}
}
