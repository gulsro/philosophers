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
	}

}
