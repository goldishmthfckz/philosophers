/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:32:00 by estegana          #+#    #+#             */
/*   Updated: 2024/03/24 19:23:20 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 1 PARSING
// 2 INITIALISATON a. prgrm, b. forks, c. philos
// 3 CREATION THREAD
// 4 DETRUIRE = free
int	main(int ac, char **av)
{
	static t_philo	philos[200];
	t_prgrm			prgrm;
	pthread_mutex_t	forks[200];

	if (!parsing(ac, av))
		return (1);
	else
	{
		initprgrm(&prgrm, av);
		initmutex(forks, ft_atoi(av[1]));
		initphilos(&prgrm, philos);
		createthreads(&prgrm);
		ft_destroy(&prgrm, forks);
	}
	return (0);
}
