##nom de l'executable
NAME = philo

##compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra
DFLAG = -g3

##fichiers sources
SRCS = 0main.c \
	1parsing.c \
	2init.c \
	3threads.c \
	utils.c \

OBJS = $(SRCS:.c=.o)

##les fichiers obj prennent le nom des fichiers sources "*.c"
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) $(DFLAG) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

norm:
	norminette $(SRCS)

re : fclean all
