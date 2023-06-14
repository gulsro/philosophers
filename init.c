#include "philo.h"

// Initializes philo struct --it will be called in init_threads_mutex_philo()
static t_philo	*init_philo_struct(t_diner *diner)
{
	t_philo *philo;
	int	i;
	long	now;

	i = 0;
	now = get_current_time();
	philo = malloc(sizeof(t_philo) * diner->number_of_philosophers);
	if (!philo)
		return (NULL);
	while (i < diner->number_of_philosophers)
	{
		philo[i].diner = diner;
		philo[i].id = i + 1;
		philo[i].eaten_meals = 0;
		philo[i].start_time = now;
		philo[i].last_meal_time = philo[i].start_time;
		philo[i].left_fork_id = i + 1;
     		if (philo[i].id == diner->number_of_philosophers)
		{
			philo[i].right_fork_id = 1;
		}
		else
		{
			philo[i].right_fork_id = i + 2;
		}
		philo[i].dead = 0;
		i++;
	}
	return (philo);
}

// Initializes both print mutex and fork mutexes --it will be called in init_threads_mutex_philo()
static int	init_mutexes(t_philo *philo)
{
	int	i;

	i = 0;
	philo->diner->fork = malloc(sizeof(pthread_mutex_t) * philo->diner->number_of_philosophers);
	if (!philo->diner->fork)
		return (0);
	while (i < philo->diner->number_of_philosophers)
	{
		if (pthread_mutex_init(&philo->diner->fork[i], NULL) != 0)
		{
			free(philo->diner->fork); //IT SHOULD DESTROY THE CREATED FORKS IN THE ARRAY?
			return (0);
		}
			i++;
	}
	philo->diner->print = malloc(sizeof(pthread_mutex_t));
	if (!philo->diner->print)
	{
		free(philo->diner->fork);
		return (0);
	}
	if (pthread_mutex_init(philo->diner->print, NULL) != 0)
	{
		destroy_fork_mutex(philo->diner);
		free(philo->diner->print);
		return (0);
	}
	return (1);
}

//Joins philo's threads and  monitor_thread thread -- will be called in init_threads_mutex_philo()
int	join_threads(t_diner *diner)
{
	int	i;
	pthread_t	*thread_arr;

	i = 0;
	thread_arr = diner->thread_arr;
	while (i < diner->number_of_philosophers)
	{
		if (pthread_join(diner->thread_arr[i], NULL) != 0)
		{
			return (0);
		}
		i++;
	}
	if (pthread_join(*diner->monitor_thread, NULL) != 0)
	{
		return (0);
	}
	return (1);
}

// Creates threads, philo's array and monitor_thread (a seperated thread for monitor_threading others threads) --it will be called in init_threads_mutex_philo()
static int	create_threads(t_diner *diner, t_philo *philo)
{
	int	i;

	i = 0;
	diner->thread_arr = malloc(sizeof(pthread_t) * diner->number_of_philosophers);
	if (!diner->thread_arr)
		return (0);
	while (i < diner->number_of_philosophers)
	{
		if (pthread_create(&diner->thread_arr[i], NULL, (void *)routine, (void *)&philo[i]) != 0)
		{
			if (join_thread_cleanup(diner, 1) == 0)
			{
				print_error("Pthread_join() is failed\n");
				free(diner->thread_arr);
				return (0);
			}
		}
		i++;
	}
	diner->monitor_thread = malloc(sizeof(pthread_t));
	if (!diner->monitor_thread)
	{
		free(diner->thread_arr);
		return (0);
	}
	if (pthread_create(diner->monitor_thread, NULL, (void *)monitoring, (void *)philo) != 0)
	{
		if (join_thread_cleanup(diner, 0) == 0)
		{
			print_error("Pthread_join() is failed\n");
			free(diner->thread_arr);
			return (0);
		}
	}
	return (1);
}

void	init_threads_mutex_philo(t_diner *diner)
{
	t_philo *philo;


	philo = init_philo_struct(diner);
	if (!philo)
	{
		print_error("Philo struct can not be created\n");
		return ;
	}
	if (init_mutexes(philo) == 0)
    	{
                print_error("Pthread_mutex_init() is failed\n");
    	}
	if (create_threads(philo->diner, philo) == 0)
	{
		print_error("Pthread_create() is failed\n");
		return ;
	}
	if (join_threads(diner) == 0)
	{
		print_error("Pthread_join() is failed\n");
		free_all(diner);
		return ;
	}
}
