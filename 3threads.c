/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:04 by estegana          #+#    #+#             */
/*   Updated: 2024/03/19 18:19:06 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	routine(void *philos)
{
	t_philo	*tmp;

	tmp = (t_philo *)philos;
	if (tmp->id % 2 == 0)
		ft_usleep(1);
	while (!loop(tmp))
	{
		eat(tmp);
		dream(tmp);
		think(tmp);
	}
	return (philos);
}

//
void	monitor(void *philos)
{
	t_philo	*tmp;

	tmp = (t_philo *)philos;
	while (1)
	{
		if (checkdead(tmp) == 1 || checkeat(tmp) == 1)
			break ;
	}
	return (philos);
}

//----------------- 3 CREATION THREADS ----------------
//creer un thread ac le monitor pr t
//creer thread par philo
//joindre thread t
//joindre thread philos
int	createthreads(t_program *prgrm, pthread_mutex_t *forks)
{
	pthread_t	t;
	int			i;

	if (pthread_create(&t, NULL, &monitor, prgrm->philos) != 0)
		ft_destroy(prgrm, forks);
	while (i < prgrm->philos[0].nbphilos)
	{
		if (pthread_create(&prgrm->philos[i].thread, NULL, &routine, &prgrm->philos[i]) != 0)
			ft_destroy(prgrm, forks);
	}
	i = 0;
	if (pthread_join(t, NULL) != 0)
		ft_destroy(prgrm, forks);
	while (i < prgrm->philos[0].nbeattimes)
	{
		if (pthread_join(prgrm->philos[i].thread, NULL) != 0)
			ft_destroy(prgrm, forks);
			i++;
	}
	return (0);
}
