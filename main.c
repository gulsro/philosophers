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
	printf("now time = %ld\n", get_current_time());
//	printf("elapsed time = %ld\n", elapsed_time());
	init_threads_mutex_philo(diner);
	pthread_detach(*diner->monitor);
//	if (pthread_join(*diner->monitor, NULL) != 0)
//	{
//		return (0);
//	}
	return (0);
}
