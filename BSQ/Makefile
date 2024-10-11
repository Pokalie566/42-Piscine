CFLAGS = -Wall -Werror -Wextra

CC = cc

NAME = bsq

SRC = ./\
      
OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
