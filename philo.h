/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <estegana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:40:45 by estegana          #+#    #+#             */
/*   Updated: 2024/03/23 19:37:10 by estegana         ###   ########.fr       */
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
	int				mealsgoal;//cb de meals doit graille
	int				dead;//0 si alive, 1 si mort
	pthread_mutex_t	mutexeat;
	struct s_prgrm	*prgrm;
	struct timeval	last_meal;
}				t_philo;

typedef struct s_prgrm
{
	t_philo			*philos;
	int				totalphilos;//nb total de philos
	int				t_die;//tps avant de mourir (av2)
	int				t_eat;//tps pr graille (av3)
	int				t_sleep;//tps pr dodo (av4)
	int				musteat;//**optional** nb de fois a graille avant fin de programme (av5)
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	flag_mutex;
	pthread_mutex_t	mutexeat;
	int				flag_death;
	pthread_mutex_t	*forks;
	struct timeval	t_init;
}				t_prgrm;

//------------------ 1 PARSING -----------------
int		parsing(int ac, char **av);

//--------------- 2 INITIALISATION -------------
void	initprgrm(t_prgrm *prgrm, char **av);
void	initmutex(pthread_mutex_t *forks, int nbphilos);
void	initphilos(t_prgrm *prgrm, t_philo *philos);

//---------------- 3 THREADS --------------------
void	*routine(void *philos);
int		createthreads(t_prgrm *prgrm);
void	*monitor(void *prgrm);
int	check_meals(t_prgrm *prgrm, t_philo *philos);
int	check_death(t_prgrm *prgrm, t_philo *philos);
void	ft_unlock(t_philo *philo, t_prgrm *data);
void	ft_print(t_prgrm *data, t_philo *philo, char *act);

//utils
int		ft_atoi(const char *str);
void	ft_destroy(t_prgrm *prgrm, pthread_mutex_t *forks);
int	ft_check_flag(t_prgrm *data);
long int	get_actual_time(void);
void	my_usleep(unsigned int time_to_wait);
int	take_forks(t_philo *philo, t_prgrm *data);
void	give_forks(t_philo *philo, t_prgrm *data);

#endif
