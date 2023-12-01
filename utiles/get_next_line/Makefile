NAME = libget_next_line.a
DEPS = get_next_line.h
CC = cc
FLAG = -Wall -Wextra -Werror
SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all