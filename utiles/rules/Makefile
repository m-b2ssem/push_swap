# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 00:33:23 by bmahdi            #+#    #+#              #
#    Updated: 2023/11/29 00:33:37 by bmahdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = librule.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ss.c utile.c pb.c pa.c rr.c rrr.c rule.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $^

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
