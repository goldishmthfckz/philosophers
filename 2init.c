/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:54:46 by estegana          #+#    #+#             */
/*   Updated: 2024/03/23 19:33:13 by estegana         ###   ########.fr       */
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
	prgrm->flag_death = 0;
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
	printf("init mutex fait\n");
}

//--------------- 2c INITIALISATION philos --------------
//initialise les compteurs a 0 pr chaque philo
void	initphilos(t_prgrm *prgrm, t_philo *philos)
{
	int	i;

	i = 0;
	prgrm->forks = malloc(sizeof(pthread_mutex_t) * prgrm->totalphilos);
	prgrm->philos = malloc(sizeof(t_philo) * prgrm->totalphilos);
	memset(prgrm->philos, 0, sizeof(t_philo) * prgrm->totalphilos);
	pthread_mutex_init(&prgrm->printf_mutex, NULL);
	pthread_mutex_init(&prgrm->flag_mutex, NULL);
	while (i < prgrm->totalphilos)
	{
		pthread_mutex_init(&prgrm->forks[i], NULL);
		pthread_mutex_init(&prgrm->philos[i].mutexeat, NULL);
		philos[i].id = i + 1;
		philos[i].dead = 0;
		philos[i].forkr = i;
		philos[i].forkl = (i + 1) % prgrm->totalphilos;
		philos[i].prgrm = prgrm;
		prgrm->philos[i].last_meal = prgrm->t_init;
		if (prgrm->musteat != -1)
			philos[i].mealsgoal = prgrm->musteat;
		i++;
		printf("+1\n");
	}
	printf("init philos faite\n");
}
