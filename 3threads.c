/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:04 by estegana          #+#    #+#             */
/*   Updated: 2024/03/22 18:47:44 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------- 3 CREATION THREADS ----------------
//creer 1 thread par philo
//creer 1 thread monitor
//joindre thread de chaque philo
//joindre thread monitor
int	createthreads(t_prgrm *prgrm, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	m;

	i = 0;
	m=0;
	printf("entree ds la creation de thread\n");
	while (i < prgrm->totalphilos)
	{
		pthread_create(&prgrm->philos[i].thread, NULL, routine, NULL);
		pthread_join(prgrm->philos[i].thread, NULL);
		i++;
	}
	//pthread_create(&m, NULL, monitor, prgrm->philos);
	//pthread_join(m, NULL);
	prgrm+=0;
	forks+=0;
	i+=0;
	m+=0;
	return (0);
}
