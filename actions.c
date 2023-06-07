#include "philo.h"

static void    taking_forks_last_philo(t_diner *diner)
{
	pthread_mutex_lock(diner->fork[diner->philo->id - 1]);
	pthread_mutex_lock(diner->fork[0]);
	pthread_mutex_lock(diner->print);
	printf("%ld %d has taken a fork\n", elapsed_time, diner->philo->id);
	pthread_mutex_unlock(diner->print);
}

//it s just a trial for even id's to grab their forks.
void	taking_forks(t_diner *diner)
{
	if (diner->philo->id == 5)
	{
		taking_fork_last_philo(diner);
	}
	else if (diner->philo->id % 2 == 1)
	{
		pthread_mutex_lock(diner->fork[diner->philo->id - 1]);
        pthread_mutex_lock(diner->fork[diner->philo->id]);
        pthread_mutex_lock(diner->print);
        printf("%ld %d has taken a fork\n", elapsed_time, diner->philo->id);
        pthread_mutex_unlock(diner->print);
	}
	else if (diner->philo->id % 2 == 0)
	{
		pthread_mutex_lock(diner->fork[diner->philo->id - 1]);
        pthread_mutex_lock(diner->fork[diner->philo->id]);
        pthread_mutex_lock(diner->print);
        printf("%ld %d has taken a fork\n", elapsed_time, diner->philo->id);
        pthread_mutex_unlock(diner->print);
	}

}

void	eating(t_diner *diner)
{
	pthread_mutex_lock(diner->print);
	printf("%ld %d is eating\n", elapsed_time, diner->philo->id);
	pthread_mutex_unlock(diner->print);
	diner->philo->eaten_meals++;
	diner->philo->last_meal_time = get_current_time();
	usleep(diner->time_to_eat);
	pthread_mutex_unlock(diner->fork[diner->philo->id]);
	pthread_mutex_unlock(diner->fork[diner->philo->id + 1]);
}

void	thinking(t_diner *diner)
{
	long	elapsed_time;
	long	now;

	now = get_current_time();
	elapsed_time = elapsed_time(now);
	pthread_mutex_lock(&diner->print);
	printf("%ld %d is thinking\n", elapsed_time, diner->philo->id);
	printf("%ld %d is thinking\n", elapsed_time, diner->philo->id);
	pthread_mutex_unlock(&diner->print);
}

void    sleeping(t_diner *diner)
{
        long    elapsed_time;
        long    now;

        now = get_current_time();
        elapsed_time = elapsed_time(now);
        pthread_mutex_lock(&diner->print);
        printf("%ld %d is sleeping\n", elapsed_time, diner->philo->id);
        pthread_mutex_unlock(&diner->print);
	usleep(diner->time_to_sleep);
}
