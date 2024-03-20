/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:54:46 by estegana          #+#    #+#             */
/*   Updated: 2024/03/20 15:37:59 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//------------- 2a INITIALISATON program ---------------
void	initprogram(t_program *prgrm, t_philo *philos)
{
	prgrm->deadflag = 0;
	prgrm->philos = philos;
	pthread_mutex_init(&prgrm->lockwrite, NULL);
	pthread_mutex_init(&prgrm->lockdead, NULL);
	pthread_mutex_init(&prgrm->lockmeal, NULL);
	printf("init program faite\n");
}

//-------------- 2b INITIALISATION forks -------------
//initialise autant de mutex qu'il y a de philos
void	initforks(pthread_mutex_t *forks, int nbphilos)
{
	int	i;

	i = 0;
	while (i < nbphilos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

//--------------- 2c INITIALISATION philos --------------
void	initphilos(t_philo *philos, t_program *prgrm,
	pthread_mutex_t *forks, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]) && i < 500)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].eaten = 0;
		initinput(av, &philos[i]);
		philos[i].t_start = t_current();
		philos[i].lastmeal = t_current();
		philos[i].lockwrite = &prgrm->lockwrite;
		philos[i].lockdead = &prgrm->lockdead;
		philos[i].lockmeal = &prgrm->lockmeal;
		philos[i].dead = &prgrm->deadflag;
		philos[i].forkl = &forks[i];
		if (i == 0)
			philos[i].forkr = &forks[philos[i].nbphilos - 1];
		else
			philos[i].forkr = &forks[i - 1];
		i++;
	}
	printf("init philos faite\n");
}

void	initinput(char **av, t_philo *philos)
{
	philos->t_die = ft_atoi(av[2]);
	philos->t_eat = ft_atoi(av[3]);
	philos->t_sleep = ft_atoi(av[4]);
	philos->nbphilos = ft_atoi(av[1]);
	if (av[5])
		philos->nbeattimes = ft_atoi(av[5]);
	else
		philos->nbeattimes = -1;
	printf("init de chaque philo faite (attributions des av)\n");
}
