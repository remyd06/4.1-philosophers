/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:53:59 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/30 17:53:59 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>	// memset, malloc, free
# include <stdio.h>		// printf
# include <unistd.h>	// write, usleep
# include <sys/time.h>	// gettimeofday
# include <pthread.h>	// pthread_create, pthread_detach, pthread_join,
						// pthread_mutex_init, pthread_mutex_destroy,
						// pthread_mutex_lock, pthread_mutex_unlock.

/* DEFINES */
# define FORK	"%lld Philo %d has taken a fork.\n"
# define EAT	"%lld Philo %d is eating.\n"
# define SLEEP	"%lld Philo %d is sleeping.\n"
# define THINK	"%lld Philo %d is thinking.\n"
# define DEAD	"\e[31m%lld Philo %d has died.\n\e[0m"
# define MEAL	"\e[32mAll philos have eaten.\n\e[0m"

/* STRUCTS */

//Boolean enum for false/true return value.
typedef enum e_bool
{
	true = 1,
	false = 0
}	t_bool;

//All information who define stats about philosophers.
typedef struct s_info
{
	int					time_eat;
	int					time_sleep;
	int					time_die;
	int					cycles;
	int					nb_philo;
	long				begin_time;
	pthread_mutex_t		death_mutex;
	t_bool				end;
}	t_info;

//Personnal information about each philophers.
typedef struct s_philo
{
	struct s_info		*info;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		curr_fork;
	pthread_t			thread;
	long				last_time_eat;
	long				meal;
	int					philo_id;

}	t_philo;

//Main struct.
typedef struct s_ms
{
	pthread_t			monitor;
	struct s_philo		philo[250];
	struct s_info		info;

}	t_ms;

/* UTILS */

//Write a custom error message and exit.
void				err_ex(char *str);
//Write a custom error message without exit.
void				err_re(char *str);
//Convert ascci to int.
int					ft_atoi(char *str);
//Return the actual time in milliseconds.
long long int		get_time(void);
//More accurate usleep with possibility to die while.
void				ft_usdie(t_philo *philo, int time_to_x);	
//Destroy all mutex before leave the program.
void				ft_leave(t_ms *ms);
//Take the righ fork first.
void				right_fork_first(t_philo *philo);
//Take the current fork first.
void				curr_fork_first(t_philo *philo);

/* MAIN FILES*/

//Initalize all the mutex for each forks.
void				init_mutex(t_ms *ms);
//Initialize all the threads for all philosophers.
void				init_thread(t_ms *ms);
//The fonction who will executed by each thread/philospohers.
void				*routine(void *args);
//A God who stops the program if a philo die.
void				*monitor_check(void *args);		

#endif
