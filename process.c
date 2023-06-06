#include "philo.h"

void	monitoring(t_diner *diner)
{
	
}

void	routine(t_diner *diner)
{
	while (1)
	{
		//if philos alive
			taking_forks(diner);
		//if alive
			eating(diner);
		//if alive
			thinking(diner);
		//if alive
			sleeping(diner);
	}
}
