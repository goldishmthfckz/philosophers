#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>//malloc, free
# include <stdio.h>//printf
# include <unistd.h>//write, usleep
# include <string.h>//memset
# include <pthread.h>//pthread_create, detach, join, mutex_init, destroy, lock, unlock

typedef struct s_philo
{
	int id;//numero
	int	nb;//cb y a de philo en tt
	int	die;
	int	eat;
	int	sleep;
	//pthread_mutex_t	mutex;
	//pthread_mutex_t	start;
	//pthread_mutex_t	end;
}				t_philo;

//parsing
int	parsing(int ac, char **av);

//utils
int	ft_atoi(const char *str);

#endif
