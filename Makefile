NAME = libftprintf.a

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I includes/

SRC_FILES = flag_handler1.c \
			ft_rot13.c \
			parse.c \
			printf.c \
			print_uint.c \
			print_pointer.c

LIB_FILES = ft_putchar.c \
			ft_putchar_fd.c \
			ft_isupper.c \
			ft_islower.c \
			ft_itoa.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strrev.c \
			ft_itoabase.c \
			ft_nbrlen.c

.PHONY = all clean fclean clean re

SRCS = $(addprefix src/, $(SRC_FILES))
LIBSRCS = $(addprefix libft/, $(LIB_FILES))

OBJ = $(SRCS:.c=.o)
LIBOBJ = $(LIBSRCS:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
		gcc -c $(CFLAGS) $< -o $@

$(LIBOBJ): %.o: %.c
		gcc -c $(CFLAGS) $< -o $@

$(NAME): $(LIBOBJ) $(OBJ)
		@ar rcs $(NAME) $(OBJ) $(LIBOBJ)
		@echo "Created libftprintf!!\n"

clean:
		@rm -rf $(OBJ) $(LIBOBJ)
		@echo "removed object files"

fclean: clean
		@rm -rf $(NAME)
		@echo "Removed executable file"

re: fclean all
