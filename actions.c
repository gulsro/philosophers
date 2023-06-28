#include "philo.h"

void    taking_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
		sleep_tight(10);
		//   usleep(200);
   // 	printf("a\n");
	//	printf("b\n");
	pthread_mutex_lock(&philo->shared_data->fork[philo->id - 1]);
	pthread_mutex_lock(&philo->shared_data->fork[philo->id % philo->shared_data->number_of_philosophers]);
	//pthread_mutex_lock(philo->shared_data->print);
	//	printf("c\n");
	printf("%ld %d has taken a fork\n", elapsed_time(philo->start_time), philo->id);
	printf("%ld %d has taken a fork\n", elapsed_time(philo->start_time), philo->id);
	//	printf("d\n");
//	sleep_tight(1);
	//pthread_mutex_unlock(philo->shared_data->print);
}

void	eating(t_philo *philo)
{
	//	printf("e\n");
	pthread_mutex_lock(philo->shared_data->print);
	//	printf("f\n");
	printf("%ld %d is eating\n", elapsed_time(philo->start_time), philo->id);
	//	printf("g\n");
	pthread_mutex_unlock(philo->shared_data->print);
	//	printf("h\n");
	philo->eaten_meals++;
//	philo->must_eat_for_philo--;
	philo->last_meal_time = get_current_time();
	sleep_tight(philo->shared_data->time_to_eat);
	pthread_mutex_unlock(&philo->shared_data->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->shared_data->fork[philo->id % philo->shared_data->number_of_philosophers]);
//	pthread_mutex_unlock(&philo->shared_data->fork[philo->id - 1]);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->shared_data->print);
	printf("%ld %d is thinking\n", elapsed_time(philo->start_time), philo->id);
//	sleep_tight(50);
	pthread_mutex_unlock(philo->shared_data->print);
}

void    sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->shared_data->print);
		printf("%ld %d is sleeping\n", elapsed_time(philo->start_time), philo->id);
	sleep_tight(philo->shared_data->time_to_sleep);
		pthread_mutex_unlock(philo->shared_data->print);
//	sleep_tight(philo->shared_data->time_to_sleep);
}
