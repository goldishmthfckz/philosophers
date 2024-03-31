/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:04 by estegana          #+#    #+#             */
/*   Updated: 2024/03/30 19:31:30 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//-------------------- routine --------------------
void	*routine(void *i_philo)
{
	t_philo	*philo;

	philo = (t_philo *)i_philo;
	while (1)
	{
		if (!eating(philo))
			break ;
		ft_write(philo->prgrm, philo, "is sleeping");
		ft_wait(philo->prgrm->t_sleep);
		if (!checkmutexdeath(philo->prgrm))
			return (NULL);
		ft_write(philo->prgrm, philo, "is thinking");
		ft_wait(((philo->prgrm->t_die - (philo->prgrm->t_eat
			+ philo->prgrm->t_sleep)) / 2));
	}
	return (NULL);
}

//---------------------- monitor --------------------
//verifie qu'aucune condition d'arret n'est atteinte;
//either aucun philo n'est mort
//nor au moins 1 a 1 repas restant a graille
void	*monitor(void *i_prgrm)
{
	t_prgrm	*prgrm;
	int		i;

	i = 0;
	prgrm = (t_prgrm *)i_prgrm;
	while (i < prgrm->totalphilos)
	{
		if (!checkmeals(prgrm, prgrm->philos))
			return (NULL);
		if (!checkdeath(prgrm, &prgrm->philos[i]))
			return (NULL);
		i++;
		if (i == prgrm->totalphilos)
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
	int			i;

	i = 0;
	while (i < prgrm->totalphilos)
	{
		if (pthread_create(&prgrm->philos[i].threadroutine,
				NULL, routine, &prgrm->philos[i]))
			return (0);
		i++;
	}
	if (pthread_create(&threadmonitor, NULL, monitor, prgrm))
		return (0);
	i = 0;
	while (i < prgrm->totalphilos)
	{
		pthread_join(prgrm->philos[i].threadroutine, NULL);
		i++;
	}
	pthread_join(threadmonitor, NULL);
	return (1);
}
