#include "philo.h"

// Initializes command line arguments, will be called in check_arguments_valid() right after input validation
void	init_arguments(t_diner *diner, int argc, char **argv)
{
        diner->number_of_philosophers = ft_atoi(argv[1]);
        diner->time_to_die = ft_atoi(argv[2]);
        diner->time_to_eat = ft_atoi(argv[3]);
        diner->time_to_sleep = ft_atoi(argv[4]);
        if (argc == 6)
		diner->must_eat = ft_atoi(argv[5]);
}

// Initializes philo struct --it will be called in main()
void	init_philos(s_diner *diner)
{
	int	i;

	i = 0;
	diner->philo = malloc(sizeof(t_philo) * diner->number_of_philosophers);
	if (!diner->philo)
		return (0);
	while (i < diner->number_of_philosophers)
	{
		diner->philo[i]->id = i + 1;
		diner->philo[i]->eaten_meals = 0;
		diner->philo[i]->start_time = get_current_time();
		diner->philo[i]->last_meal_time = diner->philo[i].start_time;
		diner->philo[i]->left_fork_id = i;
     		diner->philo[i]->right_fork_id = (i + 1) % diner->number_of_philosophers;
		diner->philo[i]->dead = 0;
		i++;
	}

}

// Initializes both print mutex and fork mutexes --it will be called in main()
int	init_mutexes(s_diner *diner)
{
	int	i;

	i = 0;
	diner->fork = malloc(sizeof(pthread_mutex_t) * diner->number_of_philosophers);
	if (!diner->fork)
		return (0);
	while (i < diner->number_of_philosophers)
	{
		if (pthread_mutex_init(&diner->fork[i], NULL) != 0)
		{
			printf("pthread_mutex_init() is failed\n")
			return (0);
		}
			i++;
	}
	diner->print = malloc(sizeof(pthread_mutex_t) * diner->number_of_philosophers);
	if (!diner->print)
	{
		free(diner->fork);
		return (0);
	}
	if (pthread_mutex_init(&diner->print, NULL) != 0)
	{
		printf("pthread_mutex_init() is failed\n");
		return (0);
	}
	return (1);
}

// Creates threads, philo's array and monitor (a seperated thread for monitoring others threads) --it will be called in main()
int	create_join_threads(t_diner *diner)
{
	int	i;

	i = 0;
	diner->t_id = malloc(sizeof(pthread_t) * diner->number_of_philosophers);
	if (!diner->t_id)
		return (0);
	while (i < diner->number_of_philosophers)
	{
		if (pthread_create(&diner->t_id[i], NULL, routine, (void *)diner->philo[i]) != 0)
		{
			printf("pthread_create() is failed\n");
			return (0);
		}
	}
	if (pthread_create(&monitor, NULL, monitoring, (void *)diner->philo) != 0)
	{
		printf("pthread_create() is failed\n");
		return (0);
	}
	if (pthread_join(monitor, NULL) != 0)
	{
		printf("pthread_join() is failed\n");
		return (0);
	}
	return (1);
}
/*
int	init_threads_mutex_philo_struct(t_diner *diner)
{
	if (init_mutexes(diner) == 0)
	{
		printf("Mutexes are not initialized\n");
		return (0);
	}
	if (create_join_threads(diner) == 0)
	{
		printf("Threads are not created\n");
		return (0);
	}
}*/
