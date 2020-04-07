# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edramire <edramire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 13:08:36 by edramire          #+#    #+#              #
#    Updated: 2020/04/07 13:17:42 by edramire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := operadores.c \
	sorting.c

OBJS := $(SRC:.c=.out)

all: $(OBJS)

%.out: %.c
	gcc -Wall -Werror -Wextra $< -o $@

clean:
	rm -rf *.o
	rm -rf *.out

