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

CFLAGS = -Wall -Wextra -Werror -g 

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)  #$(HEADER)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $< # $(HEADER)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
