NAME = philo

SRC = time.c //
	parsing.c //
	input_validation.c //
	utils.c //

HEADER = philo.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	OBJ
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
