/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1parsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:13 by estegana          #+#    #+#             */
/*   Updated: 2024/03/19 17:26:15 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//----------------- 1 PARSING -----------------
//>si mauvais nb d'args (4 ou 5) = 0 direct
//>si bon nb d'args:
//	.si pas d'entiers naturels = 0
//	.sinon = 1
int	parsing(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("enter 4 (or 5) arguments:\n");
		printf("number_of_philosophers");
		printf(" time_to_die time_to_eat");
		printf(" time_to_sleep");
		printf(" [number_of_times_each_philosopher_must_eat]\n");
	}
	else
	{
		if ((ft_atoi(av[1]) < 0) || (ft_atoi(av[2]) < 0)
			|| (ft_atoi(av[3]) < 0) || (ft_atoi(av[4]) < 0))
			printf("enter only unsigned integers\n");
		else
			return (1);
	}
	return (0);
}
