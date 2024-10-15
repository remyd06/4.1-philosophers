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

# ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>     // memset, malloc, free
#include <stdio.h>      // printf
#include <unistd.h>     // write, usleep
#include <sys/time.h>   // gettimeofday
#include <pthread.h>    // pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

/* STRUCT */

typedef enum e_bool									//Boolean enum for false/true return value.
{
	true = 1,
	false = 0
}	t_bool;

typedef struct s_info								//All information who define stats about philosophers.
{
	int		time_eat;
	int		time_sleep;
	int		time_die;
	int		nb_philo;
	long	current_time;
}	t_info;

typedef struct s_philo								//Personnal information about each philophers.
{
	struct s_info		*info;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		curr_fork;
	pthread_t			thread;
	long				last_time_eat;
	int					philo_id;

}	t_philo;

typedef struct s_ms									//Main struct.
{
	struct s_philo		*philo;
	struct s_info		info;

}	t_ms;

/* UTILS */

void	ft_puterr_ex(char *str);			//Write a custom error message and exit.
void	ft_puterr_re(char *str);			//Write a custom error message without exit.
int		ft_atoi(char *str);					//Convert ascci to int.
long	get_time();							//Return the actual time in milliseconds.

/* MAIN FILES*/

void    init_mutex(t_ms *ms);			//Initalize all the mutex for each forks.
void	init_thread(t_ms *ms);			//Initialize all the threads for all philosophers.
void	*philosophers(void *args);		//The fonction who will executed by each thread/philospohers.
void	*routine(void *args);

#endif
