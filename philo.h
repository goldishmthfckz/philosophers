/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:40:45 by estegana          #+#    #+#             */
/*   Updated: 2024/03/25 18:38:16 by estegana         ###   ########.fr       */
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
# include <sys/time.h>//gettimeofday


typedef struct s_philo
{
	pthread_t		threadroutine;//thread ac routine a join
	int				id;//kel philo?
	int				forkr;
	int				forkl;
	int				mealsgoal;//cb de meals doit graille
	int				dead;//0 si alive, 1 si mort
	pthread_mutex_t	mutexeat;
	struct s_prgrm	*prgrm;
	struct timeval	t_lastmeal;
}				t_philo;

typedef struct s_prgrm
{
	t_philo			*philos;
	int				totalphilos;//nb total de philos
	int				t_die;//tps avant de mourir (av2)
	int				t_eat;//tps pr graille (av3)
	int				t_sleep;//tps pr dodo (av4)
	int				musteat;//**optional** nb de fois a graille avant fin de programme (av5)
	pthread_mutex_t	mutexwrite;
	pthread_mutex_t	mutexdeath;
	pthread_mutex_t	mutexeat;
	int				deadflag;//1 si un philo dead
	pthread_mutex_t	*forks;
	struct timeval	t_init;
}				t_prgrm;

//------------------ 1 PARSING -----------------
int			parsing(int ac, char **av);

//--------------- 2 INITIALISATION -------------
void		initprgrm(t_prgrm *prgrm, char **av);
void		initmutex(pthread_mutex_t *forks, int nbphilos);
void		initphilos(t_prgrm *prgrm, t_philo *philos);

//---------------- 3 THREADS --------------------
void		*routine(void *philos);
int			createthreads(t_prgrm *prgrm);
void		*monitor(void *prgrm);

//----------------- 3 monitor -------------------
int			checkmeals(t_prgrm *prgrm, t_philo *philos);
int			checkdeath(t_prgrm *prgrm, t_philo *philo);

//----------------- 3 routine -------------------
void		ft_wait(int t_wait);
int			prendfourchettes(t_philo *philo, t_prgrm *prgrm);
void		remetfourchettes(t_philo *philo, t_prgrm *prgrm);
int			eating(t_philo *philo);

//utils
int			ft_atoi(const char *str);
long int	ft_time();
void		ft_write(char *str, t_philo *philos, t_prgrm *prgrm);
int			checkmutexdeath(t_prgrm *prgrm);
void		ft_destroy(t_prgrm *prgrm, pthread_mutex_t *forks);

#endif
