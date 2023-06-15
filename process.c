#include "philo.h"

void    *monitoring(t_philo *philo)
{
	int     j;

	while (1)
	{
		j = 0;
		while (j < philo->diner->number_of_philosophers && philo[j].stop == 0)
		{
			if (philo[j].eaten_meals == philo->diner->must_eat)
			{
				write(1, "NAME\n", 5);
				philo[j].stop = 1;
			}
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
		philo->diner->stop_simulation = 1;
		break ;
	}
	return NULL;
}

void *routine(t_philo *philo)
{
    if (philo->id == philo->diner->number_of_philosophers)
        sleep_tight(philo->diner->time_to_sleep);

    while (1)
    {
        if (philo->diner->stop_simulation == 1 || philo->dead == 1)
            break;

        taking_forks(philo);
        sleep_tight(50);

        if (philo->diner->stop_simulation == 1 || philo->dead == 1)
            break;

        eating(philo);

        if (philo->diner->stop_simulation == 1 || philo->dead == 1)
            break;

        sleeping(philo);

        if (philo->diner->stop_simulation == 1 || philo->dead == 1)
            break;

        thinking(philo);
    }

    return NULL;
}


/*
void	*routine(t_philo *philo)
{
	if (philo->id == philo->diner->number_of_philosophers)
		sleep_tight(philo->diner->time_to_sleep);
		//	sleeping(philo);
	while (1)
	{
		if (philo->diner->stop_simulation == 0)
		{
			taking_forks(philo);
			sleep_tight(50);
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
		if (philo->diner->stop_simulation == 1)
		{
			break ;	
		}
	}
	return 0;
}*/
