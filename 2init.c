/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:54:46 by estegana          #+#    #+#             */
/*   Updated: 2024/03/22 18:28:31 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//-------------- 2a INITIALISATION prgrm -------------
//infos generales (de l'input)
void	initprgrm(t_prgrm *prgrm, char **av)
{
	prgrm->totalphilos = ft_atoi(av[1]);
	prgrm->t_die = ft_atoi(av[2]);
	prgrm->t_eat = ft_atoi(av[3]);
	prgrm->t_sleep = ft_atoi(av[4]);
	if (av[5])
		prgrm->musteat = ft_atoi(av[5]);
	else
		prgrm->musteat = -1;
	printf("init de chaque philo faite (attributions des av)\n");
}

//-------------- 2b INITIALISATION forks -------------
//initialise autant de mutex qu'il y a de philos
void	initmutex(pthread_mutex_t *forks, int totalphilos)
{
	int	i;

	i = 0;
	while (i < totalphilos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

//--------------- 2c INITIALISATION philos --------------
//initialise les compteurs a 0 pr chaque philo
void	initphilos(t_prgrm *prgrm, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < prgrm->totalphilos)
	{
		philos[i].id = i + 1;
		philos[i].dead = 0;
		philos[i].forkr = i;
		philos[i].forkl = (i + 1) % prgrm->totalphilos;
		if (prgrm->musteat != -1)
			philos->mealsgoal = prgrm->musteat;
		i++;
	}
	printf("init philos faite\n");
}


