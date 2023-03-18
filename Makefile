NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

FT_SRC = \
	mandatory/push_swap.c mandatory/sorting.c mandatory/utile_stack_a.c mandatory/utile_stack_b.c mandatory/utile_stack_c.c mandatory/utile_stack_d.c mandatory/copy_to_b.c mandatory/copy_to_a.c  \
	mylibft/ft_atoi.c mylibft/ft_split.c mylibft/ft_substr.c mylibft/ft_strlen.c mylibft/ft_strdup.c mylibft/ft_lstadd_front_bonus.c mylibft/ft_lstnew_bonus.c  mylibft/ft_lstadd_back_bonus.c \
	mylibft/ft_lstlast_bonus.c mylibft/ft_lstsize_bonus.c \


FT_SRC_bonus = \
	bonus/checker_bonus.c bonus/utile_stack_a_bonus.c bonus/utile_stack_b_bonus.c bonus/utile_stack_c_bonus.c bonus/utile_stack_d_bonus.c  \
	bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c \
	mylibft/ft_atoi.c mylibft/ft_split.c mylibft/ft_substr.c mylibft/ft_strlen.c mylibft/ft_strdup.c mylibft/ft_lstadd_front_bonus.c mylibft/ft_lstnew_bonus.c  mylibft/ft_lstadd_back_bonus.c \
	mylibft/ft_lstlast_bonus.c mylibft/ft_lstsize_bonus.c \


OBJ = $(FT_SRC:.c=.o)

OBJ_bonus = $(FT_SRC_bonus:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o push_swap

bonus: $(OBJ_bonus)
	cc $(CFLAGS) $(OBJ_bonus) -o checker

clean:
	rm -f $(OBJ) $(OBJ_bonus)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

