#include "philo.h"

void	destroy_thread(t_diner *diner)
{
	
}

void	destroy_fork_mutex(t_diner *diner)
{
	int	i;

	i = 0;
	while (i < diner->number_of_philosophers)
	{
		pthread_mutex_destroy(&diner->fork[i], NULL);
	}
}
