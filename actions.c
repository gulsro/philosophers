#include "philo.h"

static void    taking_forks_last_philo(t_diner *diner)
{
	pthread_mutex_lock(&diner->fork[diner->philo->id - 1]);
	pthread_mutex_lock(&diner->fork[0]);
	pthread_mutex_lock(diner->print);
	printf("%ld %d has taken a fork\n", elapsed_time(get_current_time()), diner->philo->id);
	printf("%ld %d has taken a fork\n", elapsed_time(get_current_time()), diner->philo->id);
	pthread_mutex_unlock(diner->print);
}

void	taking_forks(t_diner *diner)
{
	if (diner->philo == NULL)
		return ;
	if (diner->philo->id == 5)
	{
		taking_forks_last_philo(diner);
		return ;
	}
	else if (diner->philo->id % 2 == 1)
		usleep(50);	
	pthread_mutex_lock(&diner->fork[diner->philo->id - 1]);
	pthread_mutex_lock(&diner->fork[diner->philo->id]);
	pthread_mutex_lock(diner->print);
	printf("%ld %d has taken a fork\n", elapsed_time(get_current_time()), diner->philo->id);
	printf("%ld %d has taken a fork\n", elapsed_time(get_current_time()), diner->philo->id);
	pthread_mutex_unlock(diner->print);
}

void	eating(t_diner *diner)
{
	pthread_mutex_lock(diner->print);
	printf("%ld %d is eating\n", elapsed_time(get_current_time()), diner->philo->id);
	pthread_mutex_unlock(diner->print);
	diner->philo->eaten_meals++;
	diner->philo->last_meal_time = get_current_time();
	usleep(diner->time_to_eat);
	pthread_mutex_unlock(&diner->fork[diner->philo->id]);
	pthread_mutex_unlock(&diner->fork[diner->philo->id + 1]);
}

void	thinking(t_diner *diner)
{
	pthread_mutex_lock(diner->print);
	printf("%ld %d is thinking\n", elapsed_time(get_current_time()), diner->philo->id);
	pthread_mutex_unlock(diner->print);
}

void    sleeping(t_diner *diner)
{
 	pthread_mutex_lock(diner->print);
        printf("%ld %d is sleeping\n", elapsed_time(get_current_time()), diner->philo->id);
        pthread_mutex_unlock(diner->print);
	usleep(diner->time_to_sleep);
}
