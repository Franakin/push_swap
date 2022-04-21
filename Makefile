SRC = main.c\
parsing.c\
sorting.c\
rules.c\
sort_5.c\

OBJ = $(SRC:.c=.o)

NAME = push_swap

PRINTF = ft_printf/libftprintf.a

all		:	$(NAME)

$(PRINTF):
	make -C ft_printf

$(NAME)	:	$(OBJ) $(PRINTF)
	gcc $(OBJ) -o $(NAME) $(PRINTF)

%.o		:	%.c
	gcc -Wall -Werror -Wextra -g -c $< -o $@

clean	:
	rm -f $(OBJ)
	make clean -C ft_printf

fclean	:	clean
	rm -f $(NAME)
	make fclean -C ft_printf

re		:	fclean all

.PHONY	:	all clean fclean re
