# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: netomm <netooff@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 00:04:23 by netomm            #+#    #+#              #
#    Updated: 2025/01/09 01:01:10 by netomm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
RM = rm -f
STLIBS = libs/libft_lib.a
INCDR = includes/
SRC_F = src
BLD_F = build
CFLAGS = -Wall -Wextra -Werror -g
NAME = dict
SRCS = $(SRC_F)/ft_hash_table.c	$(SRC_F)/ft_prime.c \
       $(SRC_F)/main.c	$(SRC_F)/ft_hashing.c
OBJS = $(patsubst $(SRC_F)/%.c, $(BLD_F)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(INCDR) -L. $(STLIBS)

$(BLD_F)/%.o: $(SRC_F)/%.c | $(BLD_F)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
