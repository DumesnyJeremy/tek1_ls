##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## ouaidiha
##

NAME	=	my_ls

SRC	=	src/info_file.c \
		src/my_my.c \
		src/my_getnbr.c \
		src/my_printf.c \
		src/my_put_nbr_b.c \
		src/my_put_nbr_l.c \
		src/my_put_nbr_lx.c \
		src/my_put_nbr_lxmaj.c \
		src/my_put_nbr_o.c \
		src/my_put_nbr_p.c \
		src/my_put_nbr_u.c \
		src/my_put_nbr_x.c \
		src/my_put_nbr_xmaj.c \
		src/my_strcmp.c \
		src/my_put_nbr.c \
		src/find_flags.c \
		src/flags.c \
		src/flag.c \
		src/flag_l.c \
		src/flag_l2.c \
		src/flag_rmaj.c

OBJ	=	$(SRC:.c=.o)

CFLAGS  +=	-L./ -lmy -I./include -g3

all	:	$(NAME)

$(NAME) :	$(OBJ) $(SRC)
		gcc -o $(NAME) $(OBJ) -g

clean	:
		rm -f $(OBJ)

fclean  :	clean
		rm -f $(NAME)

re	:	fclean all
