/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:46:32 by rdedola           #+#    #+#             */
/*   Updated: 2024/10/01 15:46:32 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_mutex(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->info.nb_philo)
	{
		ms->philo[i].info = &ms->info;
		pthread_mutex_init(&ms->philo[i].curr_fork, NULL);
		if (i == ms->info.nb_philo - 1)
			ms->philo[i].right_fork = &ms->philo[0].curr_fork;
		else
			ms->philo[i].right_fork = &ms->philo[i + 1].curr_fork;
		i++;
	}
	pthread_mutex_init(&ms->info.death_mutex, NULL);
}

void	init_thread(t_ms *ms)
{
	int		i;

	i = 0;
	while (i < ms->info.nb_philo)
	{
		ms->philo[i].philo_id = i + 1;
		ms->philo[i].meal = 0;
		ms->philo[i].last_time_eat = get_time();
		pthread_create(&ms->philo[i].thread, NULL, &routine, &ms->philo[i]);
		i++;
	}
	pthread_create(&ms->monitor, NULL, &monitor_check, &ms->philo);
	i = 0;
	while (i < ms->info.nb_philo)
	{
		pthread_join(ms->philo[i].thread, NULL);
		i++;
	}
	pthread_join(ms->monitor, NULL);
}
