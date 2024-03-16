/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:32:00 by estegana          #+#    #+#             */
/*   Updated: 2024/03/16 16:59:52 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*threadprocess()
{
	printf("entree dans le premier thread\n");
	pthread_exit(EXIT_SUCCESS);
}
void	initphilo(int ac, char **av, t_philo *philo)
{
	(void)ac;
	philo->nb = ft_atoi(av[1]);
	philo->die = ft_atoi(av[2]);
	philo->eat = ft_atoi(av[3]);
	philo->sleep = ft_atoi(av[4]);
}

void	createninitmutex(t_philo *philo)
{

}

int main(int ac, char **av)
{
	//pthread_t thread1;
	t_philo	*philo;

	if (!parsing(ac, av))
		return (1);
	else
	{
		philo = malloc(sizeof(philo));
		initphilo(ac, av, philo);
		createninitmutex();
	}
	free(philo);
	return (0);
}
