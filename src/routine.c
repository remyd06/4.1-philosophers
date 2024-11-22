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

void	ft_eat(t_philo *philo)
{
	if (&philo->curr_fork < philo->right_fork)
		curr_fork_first(philo);
	else
		right_fork_first(philo);
	pthread_mutex_lock(&philo->info->death_mutex);
	if (!philo->info->end)
		printf(EAT, get_time() - philo->info->begin_time, philo->philo_id);
	philo->last_time_eat = get_time();
	philo->meal++;
	pthread_mutex_unlock(&philo->info->death_mutex);
	ft_usdie(philo, philo->info->time_eat);
	pthread_mutex_unlock(&philo->curr_fork);
	pthread_mutex_unlock(philo->right_fork);
	return ;
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->death_mutex);
	if (!philo->info->end)
		printf(SLEEP, get_time() - philo->info->begin_time, philo->philo_id);
	pthread_mutex_unlock(&philo->info->death_mutex);
	ft_usdie(philo, philo->info->time_sleep);
	return ;
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->philo_id % 2 == 0)
		usleep(philo->info->time_eat * 1000);
	while (1)
	{
		pthread_mutex_lock(&philo->info->death_mutex);
		if (philo->info->end)
		{
			pthread_mutex_unlock(&philo->info->death_mutex);
			break ;
		}
		printf(THINK, get_time() - philo->info->begin_time, philo->philo_id);
		pthread_mutex_unlock(&philo->info->death_mutex);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}
