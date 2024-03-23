/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads3routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:27:52 by estegana          #+#    #+#             */
/*   Updated: 2024/03/23 19:26:51 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	ft_unlock(t_philo *philo, t_prgrm *data)
{
	pthread_mutex_unlock(&data->forks[philo->forkr]);
	pthread_mutex_unlock(&data->forks[philo->forkl]);
}

void	ft_print(t_prgrm *data, t_philo *philo, char *act)
{
	struct timeval	now;
	int				diff;

	if (ft_check_flag(data))
		return ;
	gettimeofday(&now, NULL);
	diff = ((now.tv_sec * 1000000 + now.tv_usec) - (data->t_init.tv_sec
				* 1000000 + data->t_init.tv_usec)) / 1000;
	pthread_mutex_lock(&data->printf_mutex);
	printf("%d %d %s\n", diff, philo->id, act);
	pthread_mutex_unlock(&data->printf_mutex);
}

int	eating(t_philo *philo)
{
	if (take_forks(philo, philo->prgrm))
		return (0);
	ft_print(philo->prgrm, philo, "is eating");
	pthread_mutex_lock(&philo->mutexeat);
	gettimeofday(&philo->last_meal, NULL);
	philo->mealsgoal--;
	pthread_mutex_unlock(&philo->mutexeat);
	my_usleep(philo->prgrm->t_eat);
	give_forks(philo, philo->prgrm);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (!eating(philo))
			break ;
		ft_print(philo->prgrm, philo, "is sleeping");
		my_usleep(philo->prgrm->t_sleep);
		if (ft_check_flag(philo->prgrm))
			return (NULL);
		ft_print(philo->prgrm, philo, "is thinking");
		my_usleep(((philo->prgrm->t_die - (philo->prgrm->t_eat
						+ philo->prgrm->t_sleep)) / 2));
	}
	return (NULL);
}
