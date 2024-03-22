/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3threads3routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:27:52 by estegana          #+#    #+#             */
/*   Updated: 2024/03/22 18:27:26 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philos)
{
	t_philo	*tmp;
	tmp = (t_philo *)philos;
	printf("ok routine\n");
	tmp+=0;
	return NULL;
}
