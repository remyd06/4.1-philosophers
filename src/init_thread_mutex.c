/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:46:32 by rdedola           #+#    #+#             */
/*   Updated: 2024/10/01 15:46:32 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    init_mutex(t_ms *ms)
{
    int i;

    i = 0;
    ms->philo = malloc(sizeof(t_philo) * ms->info.nb_philo);
    while (i < ms->info.nb_philo)
    {
        pthread_mutex_init(&ms->philo[i].curr_fork, NULL);
        if (i == ms->info.nb_philo - 1)
            ms->philo[i].right_fork = &ms->philo[0].curr_fork;
        else
            ms->philo[i].right_fork = &ms->philo[i + 1].curr_fork;
         i++;
    }
}

void    init_thread(t_ms *ms)
{
    int		i;

    i = 0;
    while (i < ms->info.nb_philo)
    {
        ms->philo[i].philo_id = i + 1;
        ms->philo[i].info = &ms->info;
        pthread_create(&ms->philo[i].thread, NULL, &routine, &ms->philo[i]);
		i++;
    }
    i = 0;
    while (i < ms->info.nb_philo)
    {
        pthread_join(ms->philo[i].thread, NULL);
        i++;
    }
}
