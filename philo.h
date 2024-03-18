/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:40:45 by estegana          #+#    #+#             */
/*   Updated: 2024/03/18 18:58:57 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>//malloc, free
# include <stdio.h>//printf
# include <unistd.h>//write, usleep
# include <string.h>//memset
# include <pthread.h>//pthread_create, detach, join
//mutex_init, destroy, lock, unlock
#include <sys/time.h>//gettimeofday

typedef struct s_philo
{
	pthread_t		thread;
	int				nbphilos;//nb total de philos
	int				id;//kel philo?
	int				t_die;//tps avant de mourir (av2)
	int				t_eat;//tps pr graille (av3)
	int				t_sleep;//tps pr dodo (av4)
	int				nbeattimes;//**optional** nb de fois a graille avant fin de programme (av5)
	int				*dead;
	int				eating;
	int				eaten;
	int				lastmeal;
	int				t_start;
	pthread_mutex_t	*forkr;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*lockdead;
	pthread_mutex_t	*lockmeal;
	pthread_mutex_t	*lockwrite;
}				t_philo;

typedef struct s_program
{
	t_philo			*philos;//tableau (structure) de tous les philos
	pthread_mutex_t	lockdead;
	pthread_mutex_t	lockmeal;
	pthread_mutex_t	lockwrite;
	int	deadflag;//if = 1, philo routine (which is a loop) stops
}				t_program;

//parsing
int		parsing(int ac, char **av);

//utils
int		ft_atoi(const char *str);
void	ft_destroy(t_program *prgrm, pthread_mutex_t *forks);
int		t_current(void);

#endif
