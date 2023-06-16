#include "philo.h"

void    *monitoring(t_philo *philo)
{
	int     j;

	while (1)
	{
		j = 0;
		while (j < philo->diner->number_of_philosophers && philo[j].stop == 0 && philo[j].dead == 0)
		{
		//	write(1, "NAME\n", 5);
			if (philo[j].eaten_meals == philo->diner->must_eat)
			{
//				printf("philo %d stops. %d\n", philo[j].id, philo->diner->number_of_philosophers);
				philo[j].stop = 1;
			}
			if (get_current_time() - philo[j].last_meal_time > philo->diner->time_to_die)
			{
				pthread_mutex_lock(philo->diner->print);
				printf("%ld %d died\n", elapsed_time(philo->start_time), philo[j].id);
				pthread_mutex_unlock(philo->diner->print);
				printf("I AM DEAD\n");
				philo[j].dead = 1;
				philo->diner->stop_simulation = 1;
				break ;
				//	return NULL;
			}
			
			j++;
		}
		if (philo[j].dead == 1)
			break ;
	//	printf("SOOO COOOOOL\n");
	}
	philo->diner->stop_simulation = 1;
	return NULL;
}

void *routine(t_philo *philo)
{
    if (philo->id == philo->diner->number_of_philosophers)
        sleep_tight(philo->diner->time_to_sleep);

    while (1)
    {
//		printf("dead is %d\n", philo->dead);
		printf("before FORKS philo stop is %d\n", philo->stop);
        if (philo->diner->stop_simulation == 1 || philo->dead == 1)
		{
		 	printf("breaK before FORKS %d\n", philo->id);	
		   	return NULL;
		}
        taking_forks(philo);
	//	printf("do we come here?\n");

//		printf("dead is %d\n", philo->dead);
        printf("before EATING philo stop is %d\n", philo->stop);
		if (philo->diner->stop_simulation == 1 || philo->dead == 1)
		{
			printf("breaK before EATING %d\n", philo->id);
            return NULL;
		}
	//	printf("do we come here2?\n");
        eating(philo);
	
//		printf("dead is %d\n", philo->dead);
		printf("before SLEEPING philo stop is %d\n", philo->stop);
        if (philo->diner->stop_simulation == 1 || philo->dead == 1)
		{
			printf("breaK before SLEEPING %d\n", philo->id);
	 		return NULL;
	}

        sleeping(philo);

//		printf("dead is %d\n", philo->dead);
		printf("before THINK philo stop is %d\n", philo->stop);
        if (philo->diner->stop_simulation == 1 || philo->dead == 1)
		{
		   printf("breaK before THINK %d\n", philo->id);	
		 	return NULL;
		}
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
