SRC_NAME = others/ft_atoi.c is/ft_isalpha.c is/ft_isprint.c lst/ft_lstdel.c\
	lst/ft_lstmap.c mem/ft_memccpy.c mem/ft_memcpy.c mem/ft_memset.c\
	print/ft_putendl.c print/ft_putnbr_fd.c str/ft_strcat.c str/ft_strcmp.c\
	str/ft_strdup.c str/ft_striteri.c str/ft_strlen.c str/ft_strncat.c\
	str/ft_strndup.c str/ft_strnstr.c str/ft_strstr.c others/ft_tolower.c\
	mem/ft_bzero.c is/ft_isascii.c others/ft_itoa.c lst/ft_lstdelone.c\
	lst/ft_lstnew.c mem/ft_memchr.c mem/ft_memdel.c print/ft_putchar.c\
	print/ft_putendl_fd.c print/ft_putstr.c str/ft_strchr.c str/ft_strcpy.c\
	str/ft_strequ.c str/ft_strjoin.c str/ft_strmap.c str/ft_strncmp.c\
	str/ft_strnequ.c str/ft_strrchr.c str/ft_strsub.c others/ft_toupper.c\
	is/ft_isalnum.c is/ft_isdigit.c lst/ft_lstadd.c lst/ft_lstiter.c\
	mem/ft_memalloc.c mem/ft_memcmp.c mem/ft_memmove.c print/ft_putchar_fd.c\
	print/ft_putnbr.c print/ft_putstr_fd.c str/ft_strclr.c str/ft_strdel.c\
	str/ft_striter.c str/ft_strlcat.c str/ft_strmapi.c str/ft_strncpy.c\
	str/ft_strnew.c str/ft_strsplit.c str/ft_strtrim.c is/ft_islower.c\
	is/ft_isupper.c is/ft_isspace.c is/ft_isblank.c others/ft_hex_to_bin.c\
	print/ft_putwchar.c print/ft_putwstr.c others/ft_itoa_base.c\
	str/ft_strtoupper.c getnextline/get_next_line.c\
	ft_printf/src/ft_printf.c ft_printf/src/fill_list.c ft_printf/src/padding.c\
	ft_printf/src/length_handler.c ft_printf/src/char_handler.c\
	ft_printf/src/nb_handler.c ft_printf/src/wide_char_handler.c\
	ft_printf/src/utils.c ft_printf/src/utils2.c ft_printf/src/pf_itoa_base.c\
	ft_printf/src/pf_strdup.c others/ft_swap.c
OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRC = $(SRC_NAME)
OBJ = $(OBJ_NAME)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette include/*.h

.PHONY: all, clean, fclean, re
