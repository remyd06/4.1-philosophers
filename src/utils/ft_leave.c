/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leave.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:01:39 by rdedola           #+#    #+#             */
/*   Updated: 2024/11/21 15:27:59 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_leave(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->info.nb_philo)
	{
		pthread_mutex_destroy(&ms->philo[i].curr_fork);
		i++;
	}
	pthread_mutex_destroy(&ms->info.death_mutex);
}
