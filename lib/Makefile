NAME = libmy.a

SRC =	my_find_prime_sup.c	\
	my_getnbr.c		\
	my_getnbr_base.c	\
	my_putnbr_base_ld.c	\
	my_is_prime.c		\
	my_isneg.c		\
	my_power_rec.c		\
	my_printf.c		\
	my_putnbr.c		\
	my_putnbr_ld.c		\
	my_putchar.c		\
	my_putnbr_base.c	\
	my_putstr.c		\
	my_revstr.c		\
	my_showstr.c		\
	my_sort_int_tab.c	\
	my_square_root.c	\
	my_str_isalpha.c	\
	my_str_islower.c	\
	my_str_isnum.c		\
	my_str_isprintable.c	\
	my_str_isupper.c	\
	my_strcapitalize.c	\
	my_strcat.c		\
	my_strcmp.c		\
	my_strcpy.c		\
	my_strlcat.c		\
	my_strlen.c		\
	my_strlowcase.c		\
	my_strncat.c		\
	my_strncmp.c		\
	my_strncpy.c		\
	my_strstr.c		\
	my_strupcase.c		\
	my_swap.c		\
	my_str_to_wordtab.c	\
	my_show_wordtab.c	\
	my_func.c		\
	my_func_.c		\
	my_isnum.c		\
	get_next_line.c		\

AR = ar rc

RM = rm -f

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
