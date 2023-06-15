#include "philo.h"

void    taking_forks(t_philo *philo)
{
//	int	left_fork;
//	int	right_fork;

//	left_fork = philo->id - 1;
//	right_fork = philo->id % philo->diner->number_of_philosophers;
    if (philo->id % 2 == 1)
        usleep(200);
    	
  /*  	if (left_fork < right_fork)
	{
		pthread_mutex_lock(&philo->diner->fork[left_fork]);
		pthread_mutex_lock(&philo->diner->fork[right_fork]);
    	}
	else 
    	{
        	pthread_mutex_lock(&philo->diner->fork[right_fork]);
        	pthread_mutex_lock(&philo->diner->fork[left_fork]);
   	}*/
	pthread_mutex_lock(&philo->diner->fork[philo->id - 1]);
    pthread_mutex_lock(&philo->diner->fork[philo->id % philo->diner->number_of_philosophers]);
    pthread_mutex_lock(philo->diner->print);
    printf("%ld %d has taken a fork\n", elapsed_time(philo->start_time), philo->id);
    printf("%ld %d has taken a fork\n", elapsed_time(philo->start_time), philo->id);
    pthread_mutex_unlock(philo->diner->print);
}

void	eating(t_philo *philo)
{
//	int     left_fork;
       // int     right_fork;

     //   left_fork = philo->id - 1;
     //   right_fork = philo->id % philo->diner->number_of_philosophers;
	pthread_mutex_lock(philo->diner->print);
	printf("%ld %d is eating\n", elapsed_time(philo->start_time), philo->id);
	pthread_mutex_unlock(philo->diner->print);
	philo->eaten_meals++;
//	philo->must_eat_for_philo--;
	philo->last_meal_time = get_current_time();
	sleep_tight(philo->diner->time_to_eat);
	/*	if (philo->id == philo->diner->number_of_philosophers)
	{
		pthread_mutex_unlock(&philo->diner->fork[philo->id - 1]);
		pthread_mutex_unlock(&philo->diner->fork[0]);
	}
	else
	{
		pthread_mutex_unlock(&philo->diner->fork[philo->id - 1]);
		pthread_mutex_unlock(&philo->diner->fork[philo->id]);
	}*/
/*	if (left_fork < right_fork)
        {
                pthread_mutex_unlock(&philo->diner->fork[left_fork]);
                pthread_mutex_unlock(&philo->diner->fork[right_fork]);
        }
        else
        {
                pthread_mutex_unlock(&philo->diner->fork[right_fork]);
                pthread_mutex_unlock(&philo->diner->fork[left_fork]);
        }*/
	pthread_mutex_unlock(&philo->diner->fork[philo->id % philo->diner->number_of_philosophers]);
	pthread_mutex_unlock(&philo->diner->fork[philo->id - 1]);
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
//	usleep(philo->diner->time_to_sleep);
	sleep_tight(philo->diner->time_to_sleep);
}
