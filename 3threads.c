/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:04 by estegana          #+#    #+#             */
/*   Updated: 2024/03/23 19:09:28 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------- 3 CREATION THREADS ----------------
int	createthreads(t_prgrm *prgrm)
{
	pthread_t	m;
	int	i;

	i = 0;
	printf("entree ds la creation des threads\n");
	while (i < prgrm->totalphilos)
	{
		if (pthread_create(&prgrm->philos[i].thread, NULL, routine, &prgrm->philos[i]))
			return (0);
		i++;
	}
	if (pthread_create(&m, NULL, monitor, prgrm))
		return (0);
	i = 0;
	while (i < prgrm->totalphilos)
	{
		pthread_join(prgrm->philos[i].id, NULL);
		i++;
	}
	pthread_join(m, NULL);
	return (1);
}
