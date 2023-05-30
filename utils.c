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
