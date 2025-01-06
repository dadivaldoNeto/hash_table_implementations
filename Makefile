# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: netomm <netooff@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 00:04:23 by netomm            #+#    #+#              #
#    Updated: 2025/01/06 02:00:35 by netomm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
RM = rm -f
INCDR = includes
SRC_F = src
BLD_F = build
CFLAGS = -Wall -Wextra -g
NAME = dictionary
SRC = $(wildcard $(SRC_F)/*.c)
OBJS = $(patsubst $(SRC_F)/%.c, $(BLD_F)/%.o, $(SRC))

all: $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(OBJS)
.PHONY: clean all
