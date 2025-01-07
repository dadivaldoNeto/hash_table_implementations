# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: netomm <netooff@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 00:04:23 by netomm            #+#    #+#              #
#    Updated: 2025/01/07 13:22:07 by netomm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
RM = rm -f
INCDR = includes
SRC_F = src
BLD_F = build
CFLAGS = -Wall -Wextra -g
NAME = dictionary
SRCS = $(wildcard $(SRC_F)/*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $< -o $@ -I $(INCDR)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDR)

clean:
	$(RM) $(OBJS)

.PHONY: all clean 
