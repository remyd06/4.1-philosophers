/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:12:03 by rdedola           #+#    #+#             */
/*   Updated: 2024/11/22 13:35:59 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_bool	check_meals(t_philo *philo, int i)
{
	if (philo->info->cycles > 0)
	{
		if (philo[i].meal == philo->info->cycles)
			i++;
		if (i == philo->info->nb_philo)
		{
			philo->info->end = true;
			printf(MEAL);
			pthread_mutex_unlock(&philo->info->death_mutex);
			return (true);
		}
		return (false);
	}
	return (false);
}

void	*monitor_check(void *args)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)args;
	while (1)
	{
		i = -1;
		while (++i < philo->info->nb_philo)
		{
			pthread_mutex_lock(&philo->info->death_mutex);
			if ((get_time() - philo[i].last_time_eat) > philo->info->time_die)
			{
				philo->info->end = true;
				printf(DEAD, get_time() - philo->info->begin_time,
					philo->philo_id);
				pthread_mutex_unlock(&philo->info->death_mutex);
				return (NULL);
			}
			if (check_meals(philo, i))
				return (NULL);
			pthread_mutex_unlock(&philo->info->death_mutex);
			usleep(6000);
		}
	}
	return (NULL);
}
