# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpons <mpons@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 14:25:48 by mpons             #+#    #+#              #
#    Updated: 2022/09/03 21:46:57 by mpons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CODEDIRS	= . 

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
OBJECTS=$(patsubst %.c,%.o,$(CFILES))

LIB			= ar rc 
RAN			= ranlib

all:		$(NAME)

${NAME}:	${OBJECTS}
		 	${LIB} $@ $^
			${RAN} $@

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re



