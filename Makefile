# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 18:42:37 by fcatteau          #+#    #+#              #
#    Updated: 2023/09/21 09:26:24 by feliciencat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = srcs/philo.c \
       srcs/utils.c \
       srcs/time.c \
       srcs/routine.c \
       srcs/init.c \
	   srcs/dead_file.c \
	   srcs/routine2.c

OBJS = $(SRCS:.c=.o)

HEADERS = -I ./Includes/

CFLAGS =  -Wall -Werror -Wextra -O2

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(HEADERS) -o $(NAME) $(OBJS) -lpthread

%.o: %.c
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
