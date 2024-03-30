/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:54:46 by estegana          #+#    #+#             */
/*   Updated: 2024/03/30 19:21:27 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//-------------- 2a INITIALISATION prgrm -------------
//infos generales (de l'input)
void	initprgrm(t_prgrm *prgrm, char **av)
{
	memset(prgrm, 0, sizeof(t_prgrm));
	prgrm->totalphilos = ft_atoi(av[1]);
	prgrm->t_die = ft_atoi(av[2]);
	prgrm->t_eat = ft_atoi(av[3]);
	prgrm->t_sleep = ft_atoi(av[4]);
	if (av[5])
		prgrm->musteat = ft_atoi(av[5]);
	else
		prgrm->musteat = -1;
	gettimeofday(&prgrm->t_init, NULL);
	prgrm->deadflag = 0;
}

//--------------- 2b INITIALISATION philos --------------
//initialise les compteurs a 0 pr chaque philo
int	initphilos(t_prgrm *prgrm)
{
	int	i;

	i = 0;
	prgrm->fourchettes = malloc(sizeof(pthread_mutex_t) * prgrm->totalphilos);
	prgrm->philos = malloc(sizeof(t_philo) * prgrm->totalphilos);
	if (!prgrm->fourchettes || !prgrm->philos)
		return (0);
	memset(prgrm->philos, 0, sizeof(t_philo) * prgrm->totalphilos);
	pthread_mutex_init(&prgrm->mutexwrite, NULL);
	pthread_mutex_init(&prgrm->mutexdeath, NULL);
	while (i < prgrm->totalphilos)
	{
		pthread_mutex_init(&prgrm->fourchettes[i], NULL);
		pthread_mutex_init(&prgrm->philos[i].mutexeat, NULL);
		prgrm->philos[i].id = i + 1;
		prgrm->philos[i].prgrm = prgrm;
		prgrm->philos[i].fourchetted = i;
		prgrm->philos[i].fourchetteg = (i + 1) % prgrm->totalphilos;
		prgrm->philos[i].t_lastmeal = prgrm->t_init;
		//prgrm->philos[i].dead = 0;
		if (prgrm->musteat != -1)
			prgrm->philos[i].mealsgoal = prgrm->musteat;
		i++;
	}
	return (createthreads(prgrm));
}
