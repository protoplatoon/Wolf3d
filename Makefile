CC=		gcc

SRC=		src/image.c			\
		src/draw.c			\
		src/main.c			\
		src/calcul.c			\
		src/event.c			\
		src/event_key.c			\

NAME=		wolf3d

OBJ=		$(SRC:.c=.o)

LIB=		-L./lib/minilibx -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -lm -L./lib/ -lmy

LDFLAGS=	-o $(NAME) $(LIB)

CFLAGS=		-I./include -I/usr/include/X11

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/minilibx
		make -C ./lib
		$(CC) $(OBJ) $(LDFLAGS)
clean:
		make clean -C ./lib/minilibx
		make clean -C ./lib
		rm -f $(OBJ)

fclean:		clean
		make fclean -C ./lib
		make fclean -C ./lib/minilibx
		rm -f $(NAME)

re:		fclean all
