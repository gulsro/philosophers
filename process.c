#include "philo.h"

void    *monitoring(t_philo *philo)
{
	int     j;

	while (1)
	{
		j = 0;
		while (j < philo->diner->number_of_philosophers && philo[j].stop == 0 && philo[j].dead == 0)
		{
			if (philo[j].eaten_meals == philo->diner->must_eat)
			{
//				printf("philo %d stops. %d\n", philo[j].id, philo->diner->number_of_philosophers);
				pthread_mutex_lock(philo->diner->print);
				philo[j].stop = 1;
				pthread_mutex_unlock(philo->diner->print);
			}
			if (get_current_time() - philo[j].last_meal_time > philo->diner->time_to_die || philo[j].stop == 1)
			{
				pthread_mutex_lock(philo->diner->print);
				printf("%ld %d died\n", elapsed_time(philo->start_time), philo[j].id);
			//	pthread_mutex_unlock(philo->diner->print);
				printf("I AM DEAD\n");
				philo[j].dead = 1;
				philo->diner->stop_simulation = 1;
				pthread_mutex_unlock(philo->diner->print);
				break ;
				//	return NULL;
			}
			
			j++;
		}
		pthread_mutex_lock(philo->diner->print);
		if (philo[j].dead == 1)
		{
			printf("LOOOOk\n");
			break ;
		}
		pthread_mutex_unlock(philo->diner->print);
	//	printf("SOOO COOOOOL\n");
	}
/*	pthread_mutex_lock(philo->diner->print);
	philo->diner->stop_simulation = 1;
	pthread_mutex_unlock(philo->diner->print);*/
	return NULL;
}

void *routine(t_philo *philo)
{
 //   if (philo->id == philo->diner->number_of_philosophers)
 //       sleep_tight(philo->diner->time_to_sleep);

    while (1)
    {
		printf("%d dead is %d\n", philo->id, philo->dead);
//	printf("before FORKS philo stop is %d\n", philo->stop);
        if (philo->diner->stop_simulation == 1 || philo->dead == 1)
	{
	 	printf("breaK before FORKS %d\n", philo->id);	
	   	return NULL;
	}
        taking_forks(philo);
//	sleep_tight(100);
//		printf("dead is %d\n", philo->dead);
  //      printf("before EATING philo stop is %d\n", philo->stop);
	if (philo->diner->stop_simulation == 1 || philo->dead == 1)
	{
		printf("breaK before EATING %d\n", philo->id);
		return NULL;
	}
		
	eating(philo);
//		printf("dead is %d\n", philo->dead);
//	printf("before SLEEPING philo stop is %d\n", philo->stop);
        if (philo->diner->stop_simulation == 1 || philo->dead == 1)
	{
		printf("breaK before SLEEPING %d\n", philo->id);
		return NULL;
	}

        sleeping(philo);

//		printf("dead is %d\n", philo->dead);
//	printf("before THINK philo stop is %d\n", philo->stop);
        if (philo->diner->stop_simulation == 1 || philo->dead == 1)
	{
		printf("breaK before THINK %d\n", philo->id);	
		return NULL;
	}
        thinking(philo);
//	sleep_tight(50);
    	}
    	if (philo->diner->stop_simulation == 1 || philo->dead == 1)
        {
              printf("breaK after THINKING %d\n", philo->id);
                return NULL;
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
		if (philo->diner->stop_simulation == 0 || philo->dead == 0)
		{
			taking_forks(philo);
//			sleep_tight(50);
		}
		if (philo->diner->stop_simulation == 0 || philo->dead == 0)
		{
			eating(philo);
		}
		if (philo->diner->stop_simulation == 0 || philo->dead == 0)
		{
			sleeping(philo);
		}
		if (philo->diner->stop_simulation == 0 || philo->dead == 0)
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
