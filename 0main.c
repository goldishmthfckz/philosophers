/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:32:00 by estegana          #+#    #+#             */
/*   Updated: 2024/03/19 16:55:15 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 1 PARSING
// 2 INITIALISATON a. prgrm, b. forks, c. philos
// 3 CREATION THREAD
// 4 DETRUIRE = free
int	main(int ac, char **av)
{
	t_philo			philos[500];
	t_program		prgrm;
	pthread_mutex_t	forks[500];

	if (!parsing(ac, av))
		return (1);
	else
	{
		initprogram(&prgrm, philos);
		initforks(forks, ft_atoi(av[1]));
		initphilos(philos, &prgrm, forks, av);
		createthreads(&prgrm, forks);
		ft_destroy(&prgrm, forks);
	}
	return (0);
}
