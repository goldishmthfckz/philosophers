/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:32:00 by estegana          #+#    #+#             */
/*   Updated: 2024/03/30 15:24:12 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 1 PARSING
// 2 INITIALISATON a. prgrm, b. philos
// 3 CREATION THREAD
// 4 DETRUIRE = free
int	main(int ac, char **av)
{
	t_prgrm			prgrm;

	if (!parsing(ac, av))
		return (1);
	else
	{
		initprgrm(&prgrm, av);
		if (!initphilos(&prgrm))
			return (printf("error initialisation philos\n"), 1);
		ft_destroy(&prgrm);
	}
	return (0);
}
