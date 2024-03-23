/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads2monitor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:27:40 by estegana          #+#    #+#             */
/*   Updated: 2024/03/23 19:22:49 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_prgrm *prgrm, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < prgrm->totalphilos)
	{
		pthread_mutex_lock(&philos[i].mutexeat);
		if (philos[i].mealsgoal > 0 || (prgrm->musteat == -1))
		{
			pthread_mutex_unlock(&philos[i].mutexeat);
			return (0);
		}
		pthread_mutex_unlock(&philos[i].mutexeat);
		i++;
	}
	pthread_mutex_lock(&prgrm->flag_mutex);
	prgrm->flag_death = 1;
	pthread_mutex_unlock(&prgrm->flag_mutex);
	return (1);
}

int	check_death(t_prgrm *prgrm, t_philo *philos)
{
	struct timeval	now;
	int				diff;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(&philos->mutexeat);
	diff = ((now.tv_sec * 1000000 + now.tv_usec) - (philos->last_meal.tv_sec
				* 1000000 + philos->last_meal.tv_usec)) / 1000;
	pthread_mutex_unlock(&philos->mutexeat);
	if (diff >= prgrm->t_die)
	{
		ft_print(prgrm, philos, "died");
		pthread_mutex_lock(&prgrm->flag_mutex);
		prgrm->flag_death = 1;
		pthread_mutex_unlock(&prgrm->flag_mutex);
		return (1);
	}
	return (0);
}

void	*monitor(void *prgrm)
{
	int		i;
	t_prgrm	*tmp;

	i = 0;
	tmp = (t_prgrm *)prgrm;
	while (i < tmp->totalphilos)
	{
		if (check_meals(tmp, tmp->philos))
			return (NULL);
		if (check_death(tmp, &tmp->philos[i]))
			return (NULL);
		i++;
		if (i == tmp->totalphilos)
			i = 0;
		my_usleep(1);
	}
	return (NULL);
}
