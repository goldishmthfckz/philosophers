/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads2monitor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:27:40 by estegana          #+#    #+#             */
/*   Updated: 2024/03/22 18:25:09 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *philos)
{
	t_philo	*tmp;

	tmp = (t_philo *)philos;
	//while (1)
	{
		printf("monitor a faire\n");
		//if (checkdead(tmp) == 1 || checkeat(tmp) == 1)
		//	break ;
	}
	tmp+=0;
	return (philos);
}
