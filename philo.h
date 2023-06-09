/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 12:33:19 by gozturk       #+#    #+#                 */
/*   Updated: 2023/06/16 17:17:28 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	int	id;
	int	eaten_meals;
	long	start_time;
	long	last_meal_time;
	int	left_fork_id;
	int	right_fork_id;
	int stop;
	int	dead;
//	int	must_eat_for_philo;
	struct s_shared_data *shared_data;
}t_philo;

typedef struct s_shared_data
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	int	stop_simulation;
	pthread_t	*thread_arr;
	pthread_t	monitor_thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t *print;
	t_philo		*philo;
}t_shared_data;

//time.c
long	get_current_time(void);
long	elapsed_time(long start_time);
void    sleep_tight(long time);

//input_validation.c
int		check_validation_and_init_arguments(t_shared_data *shared_data, int argc, char **argv);
void    init_arguments(t_shared_data *shared_data, int argc, char **argv);

//utils.c
int	ft_atoi(char *str);

//error.c
void    print_error(char *msg);

//init.c
void    init_threads_mutex_philo(t_shared_data *shared_data);
int	join_threads(t_shared_data *shared_data);

//actions.c
void    taking_forks(t_philo *philo);
void    eating(t_philo *philo);
void    thinking(t_philo *philo);
void    sleeping(t_philo *philo);

//destroy.c
void    free_all(t_shared_data *shared_data);
int join_thread_cleanup(t_shared_data *shared_data, int thread_array_flag);
void    destroy_fork_mutex(t_shared_data *shared_data);

//process.c
void    *monitoring(t_philo *philo);
void    *routine(t_philo *philo);

#endif
