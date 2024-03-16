/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:38:33 by estegana          #+#    #+#             */
/*   Updated: 2024/03/16 16:36:55 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//si mauvais nb d'args (4 ou 5) = erreur
//si bon nb d'args
//>si pas d'entiers naturels = erreur
//>sinon, init *philo ac les args
int	parsing(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("enter 4 (or 5) arguments:\n");
		printf("number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	}
	else
	{
		if ((ft_atoi(av[1]) < 0) || (ft_atoi(av[2]) < 0) || (ft_atoi(av[3]) < 0)|| (ft_atoi(av[4]) < 0))
			printf("enter only unsigned integers\n");
		else
			return (1);
	}
	return (0);
}
