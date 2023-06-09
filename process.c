#include "philo.h"

void	*monitoring(t_diner *diner)
{
	int	i;

	i = 0;
	while (1)
	{
		if (diner->must_eat == 0)
		{
			diner->stop_simulation = 1;
		}
		if (elapsed_time(diner->philo[i].last_meal_time) > diner->time_to_die)
		{
			diner->philo[i].dead = 1;
			diner->stop_simulation = 1;
		}
		i++;
		i = (i + 1) % diner->number_of_philosophers;
	}
	return NULL;
}

static int	check_philo_dead(t_diner *diner)
{
	int	i;

	i = 0;
	while (1)
	{
		if (diner->philo[i].dead == 1)
			return (1);
		i++;
		i = (i + 1) % diner->number_of_philosophers;
	}
	return (0);
}

void	*routine(t_diner *diner)
{
	if (diner->philo == NULL)
		return 0;
	if (diner->philo->id == 5)
		sleeping(diner);
	while (1)
	{
		if (diner->stop_simulation == 0 || check_philo_dead(diner) != 1)
		{
			taking_forks(diner);
		}
		if (diner->stop_simulation == 0 || check_philo_dead(diner) != 1)
		{
			eating(diner);
		}
		if (diner->stop_simulation == 0 || check_philo_dead(diner) != 1)
		{
			thinking(diner);
		}
		if (diner->stop_simulation == 0 || check_philo_dead(diner) != 1)
		{
			sleeping(diner);
		}
	//	if (diner->stop_simulation == 1)
	//		join_threads(diner);
	return (0);
	}
}
