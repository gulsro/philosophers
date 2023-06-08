#include "philo.h"

void	free_all(t_diner *diner)
{
	free(diner->t_id);
    free(diner->philo);
    free(diner);	
}

/*This funtion joins threads and does clean-up in case of an error during creation of threads.
 * Second parameter is a flag for indicating if create_thread() fails at array of philo threads or after single monitor thread.
thread_array_flag = 1 >> Function joins with created threads in the array
thread_array_flag = 0 >> Function joins all threads (array and also single monitor thread)
*/
int	join_thread_cleanup(t_diner *diner, int thread_array_flag)
{
	int	i;

	i = 0;
	if (thread_array_flag == 1)
	{	
		while (i >= 0)
		{
			if (pthread_join(diner->t_id[i], NULL) != 0)
        	{
				free_all(diner);
				return (0);
        	}
			i--;
		}
	}
	if (thread_array_flag == 0)
	{
		while (i < diner->number_of_philosophers)
    	{
        	if (pthread_join(diner->t_id[i], NULL) != 0)
        	{
            	free_all(diner);
				return 0;
        	}
        	i++;
    	}

		if (pthread_join(*diner->monitor, NULL) != 0)
    	{
        	free_all(diner);
			return 0;
    	}
	}
	free_all(diner);
	return (1);
}

void	destroy_fork_mutex(t_diner *diner)
{
	int	i;

	i = 0;
	while (i < diner->number_of_philosophers)
	{
		if (pthread_mutex_destroy(&diner->fork[i]) != 0)
		{
			print_error("pthread_mutex_destroy() is failed");
			free(diner->fork);
			return ;
		}
	}
	free(diner->fork);
}
