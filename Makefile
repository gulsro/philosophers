NAME = philo

SRC = main.c \
	time.c \
		utils.c \
		input_validation.c \
		error.c \
		init.c \
		actions.c \
		destroy.c \
		process.c

HEADER = philo.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HEADERS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
