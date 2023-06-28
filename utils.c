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
		print_error("Number of the philos are greater than INT_MAX");
		return (0);
	}
	return ((int)(n));
}
/*
void	one_philosopher(t_shared_data *shared_data)
{
	init_threads_mutex_philo(shared_data);
	
}*/
