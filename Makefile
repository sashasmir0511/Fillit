NAME := fillit
SRC := ./fillitproject/*.c
OBJS := ./fillitproject/*.o
INC := ./fillitproject/

FLAGS := -Wall -Wextra -Werror

LIBFT := libft/
L_FT := libft/libft.a

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRC) -I $(INC) -L. $(L_FT)

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

relibs:
	$(MAKE) -C $(LIBFT) re
	$(MAKE) re
