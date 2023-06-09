#include "philo.h"

// Initializes philo struct --it will be called in init_threads_mutex_philo()
static void	init_philo_struct(t_diner *diner)
{
	int	i;

	i = 0;
	diner->philo = malloc(sizeof(t_philo) * diner->number_of_philosophers);
	if (!diner->philo)
		return ;
	while (i < diner->number_of_philosophers)
	{
		diner->philo[i].id = i + 1;
		diner->philo[i].eaten_meals = 0;
		diner->philo[i].start_time = get_current_time();
		diner->philo[i].last_meal_time = diner->philo[i].start_time;
		diner->philo[i].left_fork_id = i + 1;
     		if (diner->philo[i].id == diner->number_of_philosophers)
		{
			diner->philo[i].right_fork_id = 1;
		}
		else
		{
			diner->philo[i].right_fork_id = i + 2;
		}
		diner->philo[i].dead = 0;
		i++;
	}

}

// Initializes both print mutex and fork mutexes --it will be called in init_threads_mutex_philo()
static int	init_mutexes(t_diner *diner)
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
			free(diner->fork); //IT SHOULD DESTROY THE CREATED FORKS IN THE ARRAY?
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
	if (pthread_mutex_init(diner->print, NULL) != 0)
	{
		destroy_fork_mutex(diner);
		free(diner->print);
		return (0);
	}
	return (1);
}

//Joins philo's threads and  monitor thread -- will be called in init_threads_mutex_philo()
int	join_threads(t_diner *diner)
{
	int	i;

	i = 0;
	if (!diner->t_id)
		return (0);
	while (i < diner->number_of_philosophers)
	{
		if (pthread_join(diner->t_id[i], NULL) != 0)
		{
			return (0);
		}
		i++;
	}
/*	if (pthread_join(*diner->monitor, NULL) != 0)
	{
		return (0);
	}*/
	return (1);
}

// Creates threads, philo's array and monitor (a seperated thread for monitoring others threads) --it will be called in init_threads_mutex_philo()
static int	create_threads(t_diner *diner)
{
	int	i;

	i = 0;
	diner->t_id = malloc(sizeof(pthread_t) * diner->number_of_philosophers);
	if (!diner->t_id)
		return (0);
	while (i < diner->number_of_philosophers)
	{
		if (pthread_create(&diner->t_id[i], NULL, (void *)routine, (void *)diner) != 0)
		{
			if (join_thread_cleanup(diner, 1) == 0)
			{
				print_error("Pthread_join() is failed\n");
				free(diner->t_id);
				return (0);
			}
		}
		i++;
	}
	diner->monitor = malloc(sizeof(pthread_t));
	if (!diner->monitor)
	{
		free(diner->t_id);
		return (0);
	}
	if (pthread_create(diner->monitor, NULL, (void *)monitoring, (void *)diner) != 0)
	{
		if (join_thread_cleanup(diner, 0) == 0)
		{
			print_error("Pthread_join() is failed\n");
			free(diner->t_id);
			return (0);
		}
	}
	return (1);
}

void	init_threads_mutex_philo(t_diner *diner)
{
	init_philo_struct(diner);
	if (init_mutexes(diner) == 0)
    	{
                print_error("Pthread_mutex_init() is failed\n");
    	}
	if (create_threads(diner) == 0)
	{
		print_error("Pthread_create() is failed\n");
		return ;
	}
/*	if (join_threads(diner) == 0)
	{
		print_error("Pthread_join() is failed\n");
		free_all(diner);
		return ;
	}*/
}
