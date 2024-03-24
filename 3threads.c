/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:04 by estegana          #+#    #+#             */
/*   Updated: 2024/03/24 19:27:51 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------- 3 CREATION THREADS ----------------
//threadmonitor : boucle constante qui verifie l'etat du prgrm
//threadroutine : applique une routine a chaque philo
//en fonction de l'avancement du prgrm
int	createthreads(t_prgrm *prgrm)
{
	pthread_t	threadmonitor;
	int	i;

	i = 0;
	printf("entree ds la creation des threads\n");
	while (i < prgrm->totalphilos)
	{
		if (pthread_create(&prgrm->philos[i].threadroutine, NULL, routine, &prgrm->philos[i]))
			return (0);
		i++;
	}
	if (pthread_create(&threadmonitor, NULL, monitor, prgrm))
		return (0);
	i = 0;
	while (i < prgrm->totalphilos)
	{
		pthread_join(prgrm->philos[i].id, NULL);
		i++;
	}
	pthread_join(threadmonitor, NULL);
	return (1);
}
