#include "philo.h"

int	ft_atoi(char *str)
{
	int				i;
	long long int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (n > INT_MAX)
	{
		printf("Number of the philos are greater than INT_MAX");
		return (0);
	}
	return ((int)(n));
}

//no need assign_forks anymore
/*
void	assign_forks(s_diner *diner)
{
	int	i;

	i = 0;
	diner->philo.left_fork_id = diner->philo.philo_id;
	diner->philo.right_fork_id = diner->philo.philo_id + 1;

}*/
