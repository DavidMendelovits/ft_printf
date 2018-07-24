NAME = libftprintf.a

# directories
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = includes/
LIBFT_DIR = libft/
TEST_DIR = test/

# compiler
CFLAGS = -Wall -Wextra -Werror
CFLAGs += -03 -march=native -pipe
DEBUG = -g

# src - obj files
SRCS = flag_handler1.c flag_handler2.c printf.c parse.c itoabase.c print_uint.c ft_rotX.c
OBJS = $(SRCS:.c=.o)
SRC = $(addprefix$(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(OBJS))
TEST = a.out

# lib
LIBFT = ft

INCLUDES = -I $(LIBFT_DIR)/libft.a -I includes/

all: $(NAME)

$(NAME): $(OBJ)
		@$(MAKE) -C $(LIBFT_DIR)
		@cp $(LIBFT_DIR)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "\'ft_printf\' - Library Created"

$(OBJ): $(SRC)
		@mkdir -p $(OBJDIR)
		@gcc $(CFLAGS) $(INCLUDES) -c $^
		@mv -f *.o $(OBJ_DIR)

clean:
		@make -C $(LIBFT_DIR) clean
		@/bin/rm -rf $(OBJ_DIR)
		@echo "\'ft_printf\'" OBJ_DIR removed

fclean: clean
		@make -C $(LIBFT_DIR) fclean
		@/bin/rm -f $(NAME)
		@/bin/rm -f $(TEST)
		@echo "\'ft_printf'\ Executable removed."

test: all
		gcc $(DEBUG) -w test/*.c -L . -l ftprintf $(INCLUDES) -o $(TEST)

re: fclean all

.PHONY: all clean fclean re $(NAME)
