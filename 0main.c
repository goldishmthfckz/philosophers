/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:32:00 by estegana          #+#    #+#             */
/*   Updated: 2024/03/20 15:36:40 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 1 PARSING
// 2 INITIALISATON a. prgrm, b. forks, c. philos
// 3 CREATION THREAD
// 4 DETRUIRE = free
int main(int ac, char **av)
{
	static t_philo	philos[501];
	t_program		prgrm;
	pthread_mutex_t	forks[501];

	if (!parsing(ac, av))
		return (1);
	else
	{
		initphilos(philos, &prgrm, forks, av);
		initprogram(&prgrm, philos);
		initforks(forks, ft_atoi(av[1]));
		createthreads(&prgrm, forks);
		ft_destroy(&prgrm, forks);
	}
	return (0);
}
