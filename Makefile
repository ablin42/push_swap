SRC_NAME =
SRC_PATH = src/
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra -Weverything
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	libtool -static -o $@ $^
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette include/*.h

.PHONY: all, clean, fclean, re, norme
