/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:04 by estegana          #+#    #+#             */
/*   Updated: 2024/03/25 18:41:24 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//-------------------- routine --------------------
void	*routine(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *)philo;
	printf("3b ROUTINES\n");
	while (1)
	{
		if (!eating(tmp))
			break ;
		ft_write("is sleeping", tmp, tmp->prgrm);
		ft_wait(tmp->prgrm->t_sleep);
		if (!checkmutexdeath(tmp->prgrm))
			return NULL;
		ft_write("is thinking", tmp, tmp->prgrm);
		ft_wait(((tmp->prgrm->t_die - (tmp->prgrm->t_eat + tmp->prgrm->t_sleep)) / 2));
	}
	return (NULL);
}

//---------------------- monitor --------------------
//verifie qu'aucune condition d'arret n'est atteint;
//either aucun philo n'est mort
//nor au moins 1 a 1 repas restant a graille
void	*monitor(void *prgrm)
{
	t_prgrm	*tmp;
	int	i;

	tmp = (t_prgrm *)prgrm;
	i = 0;
	printf("3a MONITOR\n");
	while (i < tmp->totalphilos)
	{
		if (!checkmeals(tmp, tmp->philos))
			return NULL;
		if (!checkdeath(tmp, &tmp->philos[i]))
			return NULL;
		i++;
		if (i == tmp->totalphilos)
			i = 0;
		ft_wait(1);
	}
	return (NULL);
}

//----------------- 3 CREATION THREADS ----------------
//threadmonitor : boucle constante qui verifie l'etat du prgrm
//threadroutine : applique une routine a chaque philo
//en fonction de l'avancement du prgrm
int	createthreads(t_prgrm *prgrm)
{
	pthread_t	threadmonitor;
	int	i;

	i = 0;
	printf("3 THREADS\n");
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
