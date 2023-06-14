#include "philo.h"

//static int      check_philo_dead(t_philo *philo)
void    *monitoring(t_philo *philo)
{
	int     j;

	while (1)
	{
		j = 0;
		while (j < philo->diner->number_of_philosophers && philo[j].diner->stop_simulation == 0)
		{
		/*	if (philo[j].eaten_meals == philo->diner->must_eat)
			{
				write(1, "NAME\n", 5);
				philo[j].diner->stop_simulation = 1;
				return NULL;
			}*/
			if (get_current_time() - philo[j].last_meal_time > philo->diner->time_to_die)
			{
				pthread_mutex_lock(philo->diner->print);
				printf("%ld %d died\n", elapsed_time(philo->start_time), philo[j].id);
				pthread_mutex_unlock(philo->diner->print);
				philo[j].dead = 1;
				return NULL;
			}
			j++;
		}
	}
	return NULL;
}

/*
void	*monitoring(t_philo *philo)
{
	while (1)
	{
		if (check_philo_dead(philo) == 1)
		{
			philo->diner->stop_simulation = 1;
			break ;
		}
//		i = (i + 1) % philo->diner->number_of_philosophers;
	}
	return NULL;
}
*/
void	*routine(t_philo *philo)
{
//	if (philo->id == philo->diner->number_of_philosophers)
//		sleeping(philo);
	while (1)
	{
		if (philo->eaten_meal == philo->diner->must_eat)
		{
			philo->diner->stop_simulation == 1;
		}
		if (philo->diner->stop_simulation == 0)
		{
			taking_forks(philo);
			usleep(50);
		}
		if (philo->diner->stop_simulation == 0)
		{
			eating(philo);
		}
		if (philo->diner->stop_simulation == 0)
		{
			sleeping(philo);
		}
		if (philo->diner->stop_simulation == 0)
		{
			thinking(philo);
		}
	/*	if (philo->eaten_meal == philo->diner->must_eat)
		{
			philo->diner->stop_simulation == 1;
		}*/
	}
	return 0;
}
