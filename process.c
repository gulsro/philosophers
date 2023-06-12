#include "philo.h"

static int      check_philo_dead(t_philo *philo)
{
        int     i;
        int     j;

        i = 0;
        while (1)
        {
                j = 0;
                while (j < philo->diner->number_of_philosophers)
                {
                        if (philo[j].must_eat_for_philo == 0)
                                return (1);
                        j++;
                }
                if (philo[i].dead == 1)
                        return (1);
                i++;
                i = (i + 1) % philo->diner->number_of_philosophers;
        }
        return (0);
}

void	*monitoring(t_philo *philo)
{
//	int	i;

//	i = 0;
	while (1)
	{
		if (check_philo_dead(philo) == 1)
		{
			philo->diner->stop_simulation = 1;
		}
		if (elapsed_time(philo->last_meal_time) > philo->diner->time_to_die)
		{
			philo->dead = 1;
			philo->diner->stop_simulation = 1;
		}
//		i = (i + 1) % philo->diner->number_of_philosophers;
	}
	return NULL;
}

void	*routine(t_philo *philo)
{
	if (philo->id == philo->diner->number_of_philosophers)
		sleeping(philo);
	while (1)
	{
		if (philo->must_eat_for_philo > 0 || philo->diner->stop_simulation == 0 || check_philo_dead(philo) != 1)
		{
			taking_forks(philo);
		}
		if (philo->must_eat_for_philo > 0 || philo->diner->stop_simulation == 0 || check_philo_dead(philo) != 1)
		{
			eating(philo);
		}
		if (philo->must_eat_for_philo > 0 || philo->diner->stop_simulation == 0 || check_philo_dead(philo) != 1)
		{
			thinking(philo);
		}
		if (philo->must_eat_for_philo > 0 || philo->diner->stop_simulation == 0 || check_philo_dead(philo) != 1)
		{
			sleeping(philo);
		}
		if (philo->diner->stop_simulation == 1 || philo->must_eat_for_philo == 0 || check_philo_dead(philo) == 1)
			join_threads(philo->diner);
	}
}
