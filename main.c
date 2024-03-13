#include "philo.h"

void	*threadprocess()
{
	printf("entree dans le premier thread\n");
	pthread_exit(EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	pthread_t thread1;

	(void)av;
	if (ac < 5 || ac > 6)
		printf("enter the 4 following arguments:\nnumber_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	else
	{
		pthread_create(&thread1, NULL, threadprocess, NULL);
		printf("thread cree\n");
	}
	return (0);
}
