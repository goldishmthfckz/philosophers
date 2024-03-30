/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads2monitor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:27:40 by estegana          #+#    #+#             */
/*   Updated: 2024/03/30 19:29:22 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkmeals(t_prgrm *prgrm, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < prgrm->totalphilos)
	{
		pthread_mutex_lock(&philos[i].mutexeat);
		if (philos[i].mealsgoal > 0 || prgrm->musteat == -1)
			return (pthread_mutex_unlock(&philos[i].mutexeat), 1);
		pthread_mutex_unlock(&philos[i].mutexeat);
		i++;
	}
	pthread_mutex_lock(&prgrm->mutexdeath);
	prgrm->deadflag = 1;
	pthread_mutex_unlock(&prgrm->mutexdeath);
	return (0);
}

//VEROUILLE mutexeat(philo)pr recup t du dernier repas, DEVEROUILLE
//si t du der repas est + long que av3
//>printf dead
//>VEROUILLE mutexflag, modifie a 1, DEVEROUILLE, renvoie 0
//sinn renvoie 1
int	checkdeath(t_prgrm *prgrm, t_philo *philo)
{
	struct timeval	t;
	int				d;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&philo->mutexeat);
	d = ((t.tv_sec * 1000000 + t.tv_usec) - (philo->t_lastmeal.tv_sec * 1000000 +
		philo->t_lastmeal.tv_usec)) / 1000;
	pthread_mutex_unlock(&philo->mutexeat);
	if (d >= prgrm->t_die)
	{
		ft_write(prgrm, philo, "died");
		pthread_mutex_lock(&prgrm->mutexdeath);
		prgrm->deadflag = 1;
		pthread_mutex_unlock(&prgrm->mutexdeath);
		return (0);
	}
	return (1);
}
