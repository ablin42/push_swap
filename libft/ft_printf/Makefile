SRC_NAME = ft_printf.c fill_list.c padding.c length_handler.c char_handler.c \
nb_handler.c  wide_char_handler.c utils.c utils2.c
LIB_SRC_NAME = pf_itoa_base.c pf_strdup.c
SRC_PATH = src/
LIB_SRC_PATH = src/lib/
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_OBJ_NAME = $(LIB_SRC_NAME:.c=.o)
NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB_OBJ = $(addprefix $(OBJ_PATH),$(LIB_OBJ_NAME))
LIBSRC = $(addprefix $(LIB_SRC_PATH),$(LIB_SRC_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	libtool -static -o $@ $^
	ar rcs $(NAME) $(OBJ) $(LIB_OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

$(OBJ_PATH)%.o: $(LIB_SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

clean:
	rm -fv $(OBJ) $(LIB_OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette include/*.h

.PHONY: all, clean, fclean, re, norme
