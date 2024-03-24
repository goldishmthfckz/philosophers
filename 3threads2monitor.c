/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads2monitor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:27:40 by estegana          #+#    #+#             */
/*   Updated: 2024/03/24 19:18:56 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//int	checkmeals(t_prgrm *prgrm, t_philo *philos)
//{

//}

//bloque l'info eat d'1 philo,
int	checkdeath(t_prgrm *prgrm, t_philo *philos)
{
	struct timeval t;
	int	d;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&philos->mutexeat);
	d = ((t.tv_sec * 1000000 + t.tv_usec) - (philos->t_lastmeal.tv_sec * 1000000 +
		philos->t_lastmeal.tv_usec));
	if (d > prgrm->t_die)
	{
		printf("%d died\n", philos->dead);
		pthread_mutex_lock(&prgrm->mutexdeath);
		prgrm->deadflag = 1;
		pthread_mutex_unlock(&prgrm->mutexdeath);
		return (0);
	}
	return (1);
}

//verifie qu'aucune condition d'arret n'est atteint;
//either aucun philo n'est mort
//nor au moins 1 a 1 repas restant a graille
void	*monitor(void *prgrm)
{
	t_prgrm	*tmp;
	int	i;

	tmp = (t_prgrm *)prgrm;
	i = 0;
	while (i < tmp->totalphilos)
	{
		//if (checkmeals(tmp, tmp->philos))
		//	return NULL;
		if (!checkdeath(tmp, &tmp->philos[i]))
			return NULL;
		i++;
		if (i == tmp->totalphilos)
			i = 0;
	}
	return (NULL);
}
