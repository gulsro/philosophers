#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int	philo_id;
	int	eaten_meals;
	long	start_time;
	long	last_meal_time;
	int	left_fork_id;
	int	right_fork_id;
	int	dead;
}t_philo;

typedef struct s_diner
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	pthread_t	*t_id;
	pthread_t	*monitor;
	pthread_mutex_t	*fork;
	pthread_mutex_t *print;
	t_philo		*philo;
}t_diner;

//time.c
long	get_current_time(void);
long	elapsed_time(long time);

//input_validation.c
int	check_arguments_valid(int argc, char **argv);
int	check_diner_possible(t_diner *diner);

//utils.c
int	ft_atoi(char *str);

//init.c
void	init_arguments(t_diner *diner, int argc, char **argv);
void    init_mutexes(s_diner *diner);
void    init_philos(s_diner *diner);
