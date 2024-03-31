/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:41:46 by estegana          #+#    #+#             */
/*   Updated: 2024/03/31 16:11:00 by estegana         ###   ########.fr       */
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

//affiche temps ac 13 chiffres en ms
long int	ft_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

//VEROUILLE mutexwrite, printf, puis DEVEROUILLE
void	ft_write(t_prgrm *prgrm, t_philo *philos, char *str)
{
	struct timeval	t;
	int				d;

	if (!checkmutexdeath(prgrm))
		return ;
	gettimeofday(&t, NULL);
	d = ((t.tv_sec * 1000000 + t.tv_usec) - (prgrm->t_init.tv_sec
				* 1000000 + prgrm->t_init.tv_usec)) / 1000;
	pthread_mutex_lock(&prgrm->mutexwrite);
	printf("%d %d %s\n", d, philos->id, str);
	pthread_mutex_unlock(&prgrm->mutexwrite);
}

//VEROUILLE mutexdeath, verifie, puis DEVEROUILLE,
//renvoie 1 ou 0 en fonction dead ou pas
int	checkmutexdeath(t_prgrm *prgrm)
{
	pthread_mutex_lock(&prgrm->mutexdeath);
	if (prgrm->deadflag == 1)
		return (pthread_mutex_unlock(&prgrm->mutexdeath), 0);
	pthread_mutex_unlock(&prgrm->mutexdeath);
	return (1);
}

void	ft_destroy(t_prgrm *prgrm)
{
	int	i;

	i = 0;
	while (i < prgrm->totalphilos)
	{
		pthread_mutex_destroy(&prgrm->fourchettes[i]);
		pthread_mutex_destroy(&prgrm->philos[i].mutexeat);
		i++;
	}
	pthread_mutex_destroy(&prgrm->mutexwrite);
	pthread_mutex_destroy(&prgrm->mutexdeath);
	free(prgrm->fourchettes);
	free(prgrm->philos);
}
