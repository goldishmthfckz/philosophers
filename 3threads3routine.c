/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads3routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:27:52 by estegana          #+#    #+#             */
/*   Updated: 2024/03/25 18:46:53 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait(int t_wait)
{
	struct timeval	t_now;
	struct timeval	t;
	long long		t_start;
	gettimeofday(&t, NULL);
	t_start = t.tv_sec * 1000000 + t.tv_usec;
	while (1)
	{
		gettimeofday(&t_now, NULL);
		if ((t_now.tv_sec * 1000000 + t_now.tv_usec) - t_start >= t_wait * 1000)
			break ;
		usleep(100);
	}
}

//
int	prendfourchettes(t_philo *philo, t_prgrm *prgrm)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&prgrm->forks[philo->forkr]);
	else
		pthread_mutex_lock(&prgrm->forks[philo->forkl]);
	ft_write("took a fork", philo, prgrm);
	if (philo->forkr == philo->forkl)
		return (pthread_mutex_unlock(&prgrm->forks[philo->forkl]), 1);
	if (philo->id % 2 == 0)
		pthread_mutex_unlock(&prgrm->forks[philo->forkl]);
	else
		pthread_mutex_unlock(&prgrm->forks[philo->forkr]);
	ft_write("took a fork", philo, prgrm);
	return (0);
}

void	remetfourchettes(t_philo *philo, t_prgrm *prgrm)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&prgrm->forks[philo->forkr]);
		pthread_mutex_unlock(&prgrm->forks[philo->forkl]);
	}
	else
	{
		pthread_mutex_unlock(&prgrm->forks[philo->forkl]);
		pthread_mutex_unlock(&prgrm->forks[philo->forkr]);
	}
}

int	eating(t_philo *philo)
{
	if (prendfourchettes(philo, philo->prgrm))
		return (0);
	ft_write("is eating", philo, philo->prgrm);
	pthread_mutex_lock(&philo->mutexeat);
	gettimeofday(&philo->t_lastmeal, NULL);
	philo->mealsgoal--;
	pthread_mutex_unlock(&philo->mutexeat);
	ft_wait(philo->prgrm->t_eat);
	remetfourchettes(philo, philo->prgrm);
	return (1);
}
