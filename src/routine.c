/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 01:12:22 by rdedola           #+#    #+#             */
/*   Updated: 2024/10/11 01:12:22 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *args)
{
	t_philo	*philo;
	long	current_time;

	philo = (t_philo *)args;
	while (1)
	{
		current_time = get_time();
		printf("%ld Philo %d is thinking...\n",current_time, philo->philo_id);
		pthread_mutex_lock(&philo->curr_fork);
		pthread_mutex_lock(philo->right_fork);
		printf("%ld Philo %d start eating.\n",current_time, philo->philo_id);
		usleep(philo->info->time_eat * 1000);
		philo->last_time_eat = get_time();
		pthread_mutex_unlock(&philo->curr_fork);
		pthread_mutex_unlock(philo->right_fork);
		printf("%ld Philo %d have finished eating.\n", current_time, philo->philo_id);
		if (current_time - philo->last_time_eat > philo->info->time_die)
		{
			printf("%ld Philo %d is dead\n", current_time, philo->philo_id);
			break ;
		}
		printf("%ld Philo %d start sleeping.\n", current_time, philo->philo_id);
		usleep(philo->info->time_sleep * 1000);
		printf("%ld Philo %d have finish to sleep.\n", current_time, philo->philo_id);
	}
	return NULL;
}
