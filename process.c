#include "philo.h"

void	*monitoring(t_diner *diner)
{
	int		i;
	long	now;

	i = 0;
	now = get_current_time();
	while (i < diner->number_of_philosophers)
	{
		if (elapsed_time(diner->philo[i]->last_meal_time) > diner->time_to_die)
		{
			diner->philo[i]->dead = 1;
			diner->stop_simulation = 1;
		}
	}

}

void	*routine(t_diner *diner)
{
	while (1)
	{
		if (diner->stop_simulation == 0 || diner->must_eat > 0)
		{
			taking_forks(diner);
		}
		if (diner->stop_simulation == 0 || diner->must_eat > 0)
		{
			eating(diner);
		}
		if (diner->stop_simulation == 0 || diner->must_eat > 0)
		{
			thinking(diner);
		}
		if (diner->stop_simulation == 0 || diner->must_eat > 0)
		{
			sleeping(diner);
		}
		else
			return ;
	}
}
