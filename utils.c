/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:41:46 by estegana          #+#    #+#             */
/*   Updated: 2024/03/18 18:58:28 by estegana         ###   ########.fr       */
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

void	ft_destroy(t_program *prgrm, pthread_mutex_t *forks)
{
	int	i;

	pthread_mutex_destroy(&prgrm->lockwrite);
	pthread_mutex_destroy(&prgrm->lockmeal);
	pthread_mutex_destroy(&prgrm->lockdead);
	i = 0;
	while (i < prgrm->philos[0].nbphilos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	t_current(void)
{
	struct timeval t;

	if(gettimeofday(&t, NULL) == -1)
		printf("gettimeofday() erreur\n");
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
