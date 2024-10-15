/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:09 by rdedola           #+#    #+#             */
/*   Updated: 2024/09/30 17:54:09 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	parser(int argc, char **argv)
{
	if (argc != 5)
		ft_puterr_ex("ERROR: Args must be only number of philo, time to die, time to eat, time to sleep");
	else if (ft_atoi(argv[1]) < 0)
		ft_puterr_ex("ERROR: Number of philo must be a positive integer");
	else if (ft_atoi(argv[2]) < 0)
		ft_puterr_ex("ERROR: Time to die must be a positive integer");
	else if (ft_atoi(argv[3]) < 0)
		ft_puterr_ex("ERROR: Time to eat must be a positive integer");
	else if (ft_atoi(argv[4]) < 0)
		ft_puterr_ex("ERROR: Time to spleep must be a positive integer");
	return (0);
}

void	init_infos(char **argv, t_ms *ms)
{
	ms->info.nb_philo = ft_atoi(argv[1]);
	ms->info.time_die = ft_atoi(argv[2]);
	ms->info.time_eat = ft_atoi(argv[3]);
	ms->info.time_sleep = ft_atoi(argv[4]);
}

int	main(int argc, char **argv)
{
	t_ms	ms;

	init_infos(argv, &ms);
	parser(argc, argv);
	init_mutex(&ms);
	init_thread(&ms);
	free(ms.philo);
	return (0);
}
