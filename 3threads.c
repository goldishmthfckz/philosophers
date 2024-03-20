/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:04 by estegana          #+#    #+#             */
/*   Updated: 2024/03/20 15:38:19 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//routine:
//loop qui tourne tq deadflag != 1
//loop impose : eat, sleep, think
void	*routine(void *philo)
{
	t_philo *tmp;

	tmp = (t_philo *)philo;
	printf("entree ds routine\n");
	printf("l'id du philo est : %i\n", tmp->id);
	tmp+=0;
	return NULL;
}

//----------------- 3 CREATION THREADS ----------------
//creer 1 thread par philo
//joindre thread de chaque philo
int	createthreads(t_program *prgrm, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	printf("entree ds la creation de thread\n");
	while (i < prgrm->philos->nbphilos)
	{
		if (!pthread_create(&prgrm->philos[i].thread, NULL, routine, &prgrm->philos[i]) != 0)
			ft_destroy(prgrm, forks);
		if (!pthread_join(prgrm->philos[i].thread, NULL) != 0)
			ft_destroy(prgrm, forks);
		i++;
	}
	return (0);
}
