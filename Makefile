NAME		= push_swap

SRCS		= push_swap.c push_swap_utils.c push_swap_valid.c \
			  push_swap_instructions.c push_swap_ins_utils.c push_swap_butterfly.c
OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= cc
RM			= rm -rf
CFLAGS		= -g3 -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(ft_printf)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
		make -C $(LIBFT_DIR)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		make clean -C $(LIBFT_DIR)

fclean: clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all  clean fclean re
