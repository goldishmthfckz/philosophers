/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:41:46 by estegana          #+#    #+#             */
/*   Updated: 2024/03/23 19:36:54 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	if (!str || !*str)
		return (0);
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * sign);
}

void	ft_destroy(t_prgrm *prgrm, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < prgrm->totalphilos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	my_usleep(unsigned int time_to_wait)
{
	struct timeval		current_time;
	struct timeval		time;
	unsigned long long	start_time;

	gettimeofday(&time, NULL);
	start_time = time.tv_sec * 1000000 + time.tv_usec;
	while (1)
	{
		gettimeofday(&current_time, NULL);
		if ((current_time.tv_sec * 1000000 + current_time.tv_usec)
			- start_time >= time_to_wait * 1000)
			break ;
		usleep(100);
	}
}

long int	get_actual_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 + now.tv_usec / 1000));
}

int	ft_check_flag(t_prgrm *data)
{
	pthread_mutex_lock(&data->flag_mutex);
	if (data->flag_death == 1)
		return (pthread_mutex_unlock(&data->flag_mutex), 1);
	pthread_mutex_unlock(&data->flag_mutex);
	return (0);
}

int	take_forks(t_philo *philo, t_prgrm *data)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&data->forks[philo->forkr]);
	else
		pthread_mutex_lock(&data->forks[philo->forkl]);
	ft_print(data, philo, "has taken a fork");
	if (philo->forkr == philo->forkl)
		return (pthread_mutex_unlock(&data->forks[philo->forkr]), 1);
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&data->forks[philo->forkl]);
	else
		pthread_mutex_lock(&data->forks[philo->forkr]);
	ft_print(data, philo, "has taken a fork");
	return (0);
}

void	give_forks(t_philo *philo, t_prgrm *data)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&data->forks[philo->forkr]);
		pthread_mutex_unlock(&data->forks[philo->forkl]);
	}
	else
	{
		pthread_mutex_unlock(&data->forks[philo->forkl]);
		pthread_mutex_unlock(&data->forks[philo->forkr]);
	}
}
