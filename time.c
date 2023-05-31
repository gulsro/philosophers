#include "philo.h"

long	get_current_time(void)
{
	long	time;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

long	elapsed_time(long start_time)
{
	long	current;
	long	elapsed_time;

	current = get_current_time();
	elapsed_time = current - time;
	return (elapsed_time);
}
