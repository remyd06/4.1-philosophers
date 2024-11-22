/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:45:42 by rdedola           #+#    #+#             */
/*   Updated: 2024/11/22 13:59:19 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	curr_fork_first(t_philo *philo)
{
	pthread_mutex_lock(&philo->curr_fork);
	pthread_mutex_lock(&philo->info->death_mutex);
	if (!philo->info->end)
		printf(FORK, get_time() - philo->info->begin_time, philo->philo_id);
	pthread_mutex_unlock(&philo->info->death_mutex);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->info->death_mutex);
	if (!philo->info->end)
		printf(FORK, get_time() - philo->info->begin_time, philo->philo_id);
	pthread_mutex_unlock(&philo->info->death_mutex);
}

void	right_fork_first(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->info->death_mutex);
	if (!philo->info->end)
		printf(FORK, get_time() - philo->info->begin_time, philo->philo_id);
	pthread_mutex_unlock(&philo->info->death_mutex);
	pthread_mutex_lock(&philo->curr_fork);
	pthread_mutex_lock(&philo->info->death_mutex);
	if (!philo->info->end)
		printf(FORK, get_time() - philo->info->begin_time, philo->philo_id);
	pthread_mutex_unlock(&philo->info->death_mutex);
}
