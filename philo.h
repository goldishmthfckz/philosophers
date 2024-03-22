/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:40:45 by estegana          #+#    #+#             */
/*   Updated: 2024/03/22 18:24:42 by estegana         ###   ########.fr       */
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
	pthread_t		thread;//thread ac routine a join
	int				id;//kel philo?
	int				forkr;
	int				forkl;
	int				mealsgoal;
	int				dead;
}				t_philo;

typedef struct s_prgrm
{
	t_philo			*philos;
	int				totalphilos;//nb total de philos
	int				t_die;//tps avant de mourir (av2)
	int				t_eat;//tps pr graille (av3)
	int				t_sleep;//tps pr dodo (av4)
	int				musteat;//**optional** nb de fois a graille avant fin de programme (av5)
}				t_prgrm;

//------------------ 1 PARSING -----------------
int		parsing(int ac, char **av);

//--------------- 2 INITIALISATION -------------
void	initprgrm(t_prgrm *prgrm, char **av);
void	initmutex(pthread_mutex_t *forks, int nbphilos);
void	initphilos(t_prgrm *prgrm, t_philo *philos);

//---------------- 3 THREADS --------------------
void	*routine(void *philos);
int		createthreads(t_prgrm *prgrm, pthread_mutex_t *forks);
void	*monitor(void *philos);

//utils
int		ft_atoi(const char *str);
void	ft_destroy(t_prgrm *prgrm, pthread_mutex_t *forks);
void	ft_usleep(size_t ms);
size_t	t_current();


#endif
