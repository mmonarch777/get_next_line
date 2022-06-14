NAME 			= gnl
NAME_BONUS		= gnl_bonus

FLAGS 			= -Wall -Wextra -Werror
CC 				= gcc

SRC 			= src/get_next_line.c	src/get_next_line_utils.c
SRC_BONUS 		= src_bonus/get_next_line_bonus.c	src_bonus/get_next_line_utils_bonus.c
MAIN 			= main/main.c

OBJ				= $(SRC:.c=.o)
OBJ_BONUS		= $(SRC_BONUS:.c=.o)
OBJ_MAIN		= $(MAIN:.c=.o)

HEADER			= ./include

all				: $(NAME)

$(NAME)			: $(OBJ) $(HEADER) $(OBJ_MAIN)
				$(CC) $(FLAGS) $(OBJ) $(OBJ_MAIN) -o $(NAME)

bonus			: $(OBJ_BONUS) $(HEADER) $(OBJ_MAIN)
				$(CC) $(FLAGS) $(OBJ_BONUS) $(OBJ_MAIN) -o $(NAME_BONUS)

%.o 			: %.c $(HEADER)
				$(CC) $(FLAGS) -Iinclude -c $< -o $@

clean			:
				rm -f src/*.o
				rm -f src_bonus/*.o
				rm -f main/*.o

fclean			: clean
				rm -f $(NAME)
				rm -f $(NAME_BONUS)

re				: fclean all

.PHONY 			: all clean fclean re