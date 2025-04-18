NAME		= push_swap
BONUS_NAME		= checker
BONUS_DIR	= ./bonus

SRCS		= push_swap.c push_swap_utils.c push_swap_valid.c \
			  push_swap_instructions.c push_swap_ins_utils.c \
			  push_swap_butterfly.c push_swap_mini_ins.c
OBJS		= $(SRCS:.c=.o)

SRCS_BONUS	= $(BONUS_DIR)/checker.c $(BONUS_DIR)/checker_utils.c \
			  $(BONUS_DIR)/checker_valid.c $(BONUS_DIR)/checker_instructions.c \
			  $(BONUS_DIR)/checker_ins_utils.c
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -I. -g3

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
		$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
		make -C $(LIBFT_DIR)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		$(RM) $(OBJS_BONUS)
		make clean -C $(LIBFT_DIR)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(BONUS_NAME)
		make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all  clean fclean re
