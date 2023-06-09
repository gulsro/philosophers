#include "philo.h"

void	*monitoring(t_diner *diner)
{
//	int	i;

//	i = 0;
	while (1)
	{
		if (diner->must_eat == 0)
		{
			diner->stop_simulation = 1;
		}
		if (elapsed_time(diner->philo->last_meal_time) > diner->time_to_die)
		{
			diner->philo->dead = 1;
			diner->stop_simulation = 1;
		}
//		i = (i + 1) % philo->diner->number_of_philosophers;
	}
	return NULL;
}

static int	check_philo_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (philo[i].dead == 1)
			return (1);
		i++;
		i = (i + 1) % philo->diner->number_of_philosophers;
	}
	return (0);
}

void	*routine(t_philo *philo)
{
//	if (diner->philo == NULL)
//		return 0;
	if (philo->id == 5)
		sleeping(philo);
	while (1)
	{
		if (philo->diner->must_eat > 0 || philo->diner->stop_simulation == 0 || check_philo_dead(philo) != 1)
		{
			taking_forks(philo);
		}
		if (philo->diner->must_eat > 0 || philo->diner->stop_simulation == 0 || check_philo_dead(philo) != 1)
		{
			eating(philo);
		}
		if (philo->diner->must_eat > 0 || philo->diner->stop_simulation == 0 || check_philo_dead(philo) != 1)
		{
			thinking(philo);
		}
		if (philo->diner->must_eat > 0 || philo->diner->stop_simulation == 0 || check_philo_dead(philo) != 1)
		{
			sleeping(philo);
		}
	//	if (diner->stop_simulation == 1)
	//		join_threads(diner);
	return (0);
	}
}
