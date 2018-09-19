SRC_NAME = error.c list.c moves.c print.c read.c utils.c changename.c sorting.c\
utils2.c
SRC_PATH = src/
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
NAME1 = checker
NAME2 = push_swap
CC = gcc -g3
CFLAGS = -Werror -Wall -Wextra #-Weverything
LIB = libft/libft.a
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ)
	cd libft && make
	$(CC) $(CFLAGS) src/checker.c -o $@ $^ $(LIB)

$(NAME2): $(OBJ)
	$(CC) $(CFLAGS) src/push_swap.c -o $@ $^ $(LIB)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME1) $(NAME2)

re: fclean all

norme:
	norminette $(SRC)
	norminette include/*.h

xd: re
	clear

val: re
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=suppressions.txt ./checker

.PHONY: all, clean, fclean, re, norme
