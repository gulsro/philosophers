#include "philo.h"

void	init_philos(s_diner *diner)
{
	int	i;

	i = 0;
	diner->philo = malloc(sizeof(pthread_t) * diner->number_of_philosophers);
	if (!diner->philo->thread)
		return (0);
	while (i < diner->number_of_philosophers)
	{
		diner->philo[i]->philo_id = i + 1;
		diner->philo[i].eaten_meals = 0;
		diner->philo[i].start_time = get_current_time();
		diner->philo[i].last_meal_time = diner->philo[i].start_time;
		diner->philo[i].left_fork_id = i;
     		diner->philo[i].right_fork_id = (i + 1) % diner->number_of_philosophers;
		i++;
	}

}

void	init_mutexes(s_diner *diner)
{
	int	i;

	i = 0;
	diner->fork = malloc(sizeof(pthread_mutex_t) * diner->number_of_philosophers);
	if (!diner->fork)
		return (0);
	while (i < diner->number_of_philosophers)
	{
		pthread_mutex_init(&diner->fork[i], NULL);
		i++;
	}
	diner->print = malloc(sizeof(pthread_mutex_t) * diner->number_of_philosophers);
	if (!diner->print)
	{
		free(diner->fork);
		return (0);
	}
	pthread_mutex_init(&diner->print, NULL);
}

void	init_arguments(t_diner *diner, int argc, char **argv)
{
	diner->number_of_philosophers = ft_atoi(argv[1]);
	diner->time_to_die = ft_atoi(argv[2]);
	diner->time_to_eat = ft_atoi(argv[3]);
	diner->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		diner->must_eat = ft_atoi(argv[5]);
}
/*
void	initialize(t_diner *diner)
{
	init_philos(diner);
	init_mutexes(diner);
}*/
