#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t philo;
	int	philo_id;
	int	eaten_meals;
	long	start_time;
	long	last_meal_time;
	int	left_fork_id;
	int	right_fork_id;
}t_philo;

typedef struct s_diner
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	pthread_mutex_t* fork;
	t_philo	philo;
}t_diner;

//time.c
long	get_current_time(void);
long	elapsed_time(long time);


