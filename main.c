#include "philo.h"

//number_of_philosophers~~time_to_die~~time_to_eat~~time_to_sleep
int main(int argc, char **argv)
{
	t_shared_data	*shared_data;

	shared_data = malloc(sizeof(t_shared_data));
	if (!shared_data)
		return (0);
	if (check_validation_and_init_arguments(shared_data, argc, argv) == 0) //check error msgs
	{
		free(shared_data);
		return (0);
	}
//	printf("now time = %ld\n", get_current_time());
//	printf("now time = %ld\n", shared_data->philo[0].start_time);
//printf("elapsed time = %ld\n", elapsed_time());
	init_threads_mutex_philo(shared_data);
//	join_threads(shared_data);
	//	printf("start time = %ld\n", shared_data->philo->start_time);
//	pthread_detach(shared_data->monitor_thread);
//	if (pthread_join(*shared_data->monitor, NULL) != 0)
//	{
//		return (0);
//	}
	return (0);
}
