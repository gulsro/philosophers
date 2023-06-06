#include "philo.h"

// Initializes philo struct --it will be called in init_threads_mutex_philo()
static void	init_philo_struct(s_diner *diner)
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
		diner->philo[i]->left_fork_id = i + 1;
     	if (diner->philo->id  == diner->number_of_philosophers)
			diner->philo[i]->right_fork_id == 1;
		else
			diner->philo[i]->right_fork_id = i + 2;
		diner->philo[i]->dead = 0;
		i++;
	}

}

// Initializes both print mutex and fork mutexes --it will be called in init_threads_mutex_philo()
static int	init_mutexes(s_diner *diner)
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
			print_error("pthread_mutex_init() is failed\n")
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
		print_error("pthread_mutex_init() is failed\n");
		//destroy fork mutexes??
		return (0);
	}
	return (1);
}

//Joins philo's threads and  monitor thread -- will be called in init_threads_mutex_philo()
static int	join_threads(t_diner *diner)
{
	int	i;

	i = 0;
	while (i < diner->number_of_philosophers)
	{
		if (pthread_join(diner->t_id[i], NULL) != 0)
		{
			print_error("pthread_join() is failed\n");
			//FREEE
			return (0);
		}
		i++;
	}
	if (pthread_join(monitor, NULL) != 0)
	{
		print_error("pthread_join() is failed\n");
		//FREE
		return (0);
	}
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
		if (pthread_create(&diner->t_id[i], NULL, routine, (void *)diner->philo[i]) != 0)
		{
			join_and_destroy_thread(diner, 1);
			return (0);
		}
	}
	if (pthread_create(&monitor, NULL, monitoring, (void *)diner->philo) != 0)
	{
		join_and_destroy_thread(diner, 0);
		return (0);
	}
	return (1);
}

void	init_threads_mutex_philo(t_diner *diner)
{
	init_philo_struct(diner);
	if (create_threads(diner) == 0)
	{
		print_error("pthread_create() is failed\n");
		return ;
	}
	if (join_threads(diner) == 0)
	{

		return ;
	}
	if (init_mutexes(diner) == 0)
    {
        return ;
    }
}
