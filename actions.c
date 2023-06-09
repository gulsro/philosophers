#include "philo.h"

static void    taking_forks_last_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->diner->fork[philo->id - 1]);
	pthread_mutex_lock(&philo->diner->fork[0]);
	pthread_mutex_lock(philo->diner->print);
	printf("%ld %d has taken a fork\n", elapsed_time(philo->start_time), philo->id);
	printf("%ld %d has taken a fork\n", elapsed_time(philo->start_time), philo->id);
	pthread_mutex_unlock(philo->diner->print);
}

void	taking_forks(t_philo *philo)
{
	if (philo->id == 5)
	{
		taking_forks_last_philo(philo);
		return ;
	}
	else if (philo->id % 2 == 1)
		usleep(50);	
	pthread_mutex_lock(&philo->diner->fork[philo->id - 1]);
	pthread_mutex_lock(&philo->diner->fork[philo->id]);
	pthread_mutex_lock(philo->diner->print);
	printf("%ld %d has taken a fork\n", elapsed_time(philo->start_time), philo->id);
	printf("%ld %d has taken a fork\n", elapsed_time(philo->start_time), philo->id);
	pthread_mutex_unlock(philo->diner->print);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->diner->print);
	printf("%ld %d is eating\n", elapsed_time(philo->start_time), philo->id);
	pthread_mutex_unlock(philo->diner->print);
	philo->eaten_meals++;
	philo->diner->must_eat--;
	philo->last_meal_time = get_current_time();
	usleep(philo->diner->time_to_eat);
	pthread_mutex_unlock(&philo->diner->fork[philo->id]);
	pthread_mutex_unlock(&philo->diner->fork[philo->id + 1]);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->diner->print);
	printf("%ld %d is thinking\n", elapsed_time(philo->start_time), philo->id);
	pthread_mutex_unlock(philo->diner->print);
}

void    sleeping(t_philo *philo)
{
 	pthread_mutex_lock(philo->diner->print);
        printf("%ld %d is sleeping\n", elapsed_time(philo->start_time), philo->id);
        pthread_mutex_unlock(philo->diner->print);
	usleep(philo->diner->time_to_sleep);
}
