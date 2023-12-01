# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 23:51:38 by bmahdi            #+#    #+#              #
#    Updated: 2023/09/24 23:52:55 by bmahdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The output library's name
NAME = libftprintf.a
HEADER = ft_printf.h

# List of source files
SRC = ft_printf.c handle_s_and_c.c handle_p.c handle_x.c handle_d.c handle_u.c\


# List of object files 
OBJ = $(SRC:.c=.o)

# Compiler and flags
CC = cc 
CFLAGS = -Wall -Wextra -Werror 


# Default rule
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule to compile source fs to object files
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files
clean:
	rm -f $(OBJ)

# Fclean rule to remove both object files and the library
fclean: clean 
	rm -f $(NAME)

# Rebuild everything
re: fclean all
