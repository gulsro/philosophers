#include "philo.h"

void	thinking(t_diner)
{
	long	elapsed_time;
	long	now;

	now = get_current_time();
	elapsed_time = elapsed_time(now);
	pthread_mutex_lock(&diner->print);
	printf("%ld %d is thinking\n", elapsed_time, diner->philo->id);
	pthread_mutex_unlock(&diner->print);
}

//still some issues with usleep. after of before print???
void    sleeping(t_diner)
{
        long    elapsed_time;
        long    now;

        now = get_current_time();
        elapsed_time = elapsed_time(now);
        pthread_mutex_lock(&diner->print);
        printf("%ld %d is sleeping\n", elapsed_time, diner->philo->id);
        pthread_mutex_unlock(&diner->print);
}
