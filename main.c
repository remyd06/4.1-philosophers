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

static void	print_parser1(char **argv)
{
	if (ft_atoi(argv[1]) <= 0)
		err_ex("\e[31mERROR: Philo >= 0 & Philo < 200.\n\e[0m");
	else if (ft_atoi(argv[1]) > 200)
		err_ex("\e[31mERROR: Philo >= 0 & Philo < 200\n\e[0m");
	else if (ft_atoi(argv[2]) < 0)
		err_ex("\e[31mERROR: Time to die > 0.\n\e[0m");
	else if (ft_atoi(argv[3]) < 60)
		err_ex("\e[31mERROR: Time to eat > 60.\n\e[0m");
	else if (ft_atoi(argv[4]) < 60)
		err_ex("\e[31mERROR: Time to spleep > 60.\n\e[0m");
	else if (ft_atoi(argv[1]) == 1)
		err_ex("\e[31m0 Philo 1 have only one fork, he died.\n\e[0m");
}

static void	print_parser2(char **argv)
{
	if (ft_atoi(argv[1]) <= 0)
		err_ex("\e[31mERROR: Philo >= 0 & Philo < 200.\n\e[0m");
	else if (ft_atoi(argv[1]) > 200)
		err_ex("\e[31mERROR: Philo >= 0 & Philo < 200\n\e[0m");
	else if (ft_atoi(argv[2]) < 0)
		err_ex("\e[31mERROR: Time to die > 0.\n\e[0m");
	else if (ft_atoi(argv[3]) < 60)
		err_ex("\e[31mERROR: Time to eat > 60.\n\e[0m");
	else if (ft_atoi(argv[4]) < 60)
		err_ex("\e[31mERROR: Time to spleep > 60.\n\e[0m");
	else if (ft_atoi(argv[5]) <= 0)
		err_ex("\e[31mERROR: Time to each philo must eat > 0.\n\e[0m");
	else if (ft_atoi(argv[1]) == 1)
		err_ex("\e[31m0 Philo 1 have only one fork, he died.\n\e[0m");
}

int	parser(int argc, char **argv)
{
	if (argc == 5)
		print_parser1(argv);
	else if (argc == 6)
		print_parser2(argv);
	else
		err_ex("\e[31mERROR: Nb of args is not correct\n\e[0m");
	return (0);
}

void	init_infos(char **argv, t_ms *ms)
{
	if (argv[5])
		ms->info.cycles = ft_atoi(argv[5]);
	else
		ms->info.cycles = 0;
	ms->info.nb_philo = ft_atoi(argv[1]);
	ms->info.time_die = ft_atoi(argv[2]);
	ms->info.time_eat = ft_atoi(argv[3]);
	ms->info.time_sleep = ft_atoi(argv[4]);
	ms->info.begin_time = get_time();
	ms->info.end = false;
}

int	main(int argc, char **argv)
{
	t_ms	ms;

	parser(argc, argv);
	init_infos(argv, &ms);
	init_mutex(&ms);
	init_thread(&ms);
	ft_leave(&ms);
	return (0);
}
