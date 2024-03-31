/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:40:45 by estegana          #+#    #+#             */
/*   Updated: 2024/03/31 16:13:57 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		threadroutine;
	int				id;
	int				fourchetted;
	int				fourchetteg;
	int				mealsgoal;
	int				dead;
	pthread_mutex_t	mutexeat;
	struct s_prgrm	*prgrm;
	struct timeval	t_lastmeal;
}				t_philo;

typedef struct s_prgrm
{
	t_philo			*philos;
	int				totalphilos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				musteat;
	pthread_mutex_t	mutexwrite;
	pthread_mutex_t	mutexdeath;
	pthread_mutex_t	mutexeat;
	int				deadflag;
	pthread_mutex_t	*fourchettes;
	struct timeval	t_init;
}				t_prgrm;

//------------------ 1 PARSING -----------------
int			parsing(int ac, char **av);

//--------------- 2 INITIALISATION -------------
void		initprgrm(t_prgrm *prgrm, char **av);
int			initphilos(t_prgrm *prgrm);

//---------------- 3 THREADS --------------------
int			createthreads(t_prgrm *prgrm);
void		*routine(void *i_philo);
void		*monitor(void *i_prgrm);

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
long int	ft_time(void);
void		ft_write(t_prgrm *prgrm, t_philo *philos, char *str);
int			checkmutexdeath(t_prgrm *prgrm);
void		ft_destroy(t_prgrm *prgrm);

#endif
