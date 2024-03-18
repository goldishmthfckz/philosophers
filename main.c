/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:32:00 by estegana          #+#    #+#             */
/*   Updated: 2024/03/18 18:57:14 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initinput()
{

}

static void	initprogram(t_program *prgrm, t_philo *philos)
{
	prgrm->deadflag = 0;
	prgrm->philos = philos;
	pthread_mutex_init(&prgrm->lockwrite, NULL);
	pthread_mutex_init(&prgrm->lockdead, NULL);
	pthread_mutex_init(&prgrm->lockmeal, NULL);
}

//initialise autant de mutex qu'il y a de philos
static void	initforks(pthread_mutex_t *forks, int nbphilos)
{
	int	i;

	i = 0;
	while (i < nbphilos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

static void	initphilos(t_philo *philos, t_program *prgrm,
	pthread_mutex_t *forks, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].eaten = 0;
		initinput(&philos[i], av);
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
}

//1. parsing
//2. initialiser prgrm, forks, philos
//3. creer threads
//4. detruire = free
int	main(int ac, char **av)
{
	t_philo			*philos;
	t_program		prgrm;
	pthread_mutex_t	*forks;

	if (!parsing(ac, av))
		return (1);
	else
	{
		initprogram(&prgrm, philos);
		initforks(forks, ft_atoi(av[1]));
		initphilos(philos, &prgrm, forks, av);
		createthreads(&prgrm, forks);
		ft_destroy(&prgrm, forks);
	}
	return (0);
}
