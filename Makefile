NAME = pipex

RM = rm -rf

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = pipex.c pipex_utils.c utils.c info.c ft_splitd.c

$(NAME) :
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all	: $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all
