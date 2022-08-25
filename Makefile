SRCS	= main.c \
		 key_hook.c 

HEAD	= miniRt.h

OBJS 	= $(SRCS:.c=.o)

NAME	= mini_rt

LIB		= ar rcs

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEAD)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS)  $(OBJS) -I./mlx -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re