/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usdie.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:09:44 by rdedola           #+#    #+#             */
/*   Updated: 2024/10/27 20:09:44 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_usdie(t_philo *philo, int time_to_x)
{
	long	start;

	start = get_time();
	while (get_time() - start < time_to_x)
	{
		pthread_mutex_lock(&philo->info->death_mutex);
		if (philo->info->end)
		{
			pthread_mutex_unlock(&philo->info->death_mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->info->death_mutex);
		usleep(60);
	}
}
