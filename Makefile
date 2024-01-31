NAME    := so_long
CFLAGS  := -g -Wall -Wextra -Werror
LIBMLX  := ./lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
GET_NEXT_LINE_Bonus := ./get_next_line

SRCS    := mapxis.c init.c init1.c test2.c map-helper.c $(GET_NEXT_LINE_Bonus)/get_next_line_bonus.c $(GET_NEXT_LINE_Bonus)/get_next_line_utils_bonus.c

OBJS    := $(SRCS:%.c=%.o)

CC      := gcc

LIBFT_DIR   := ./libft
PRINTF_DIR  := ./ft_printf


LIBFT   := $(LIBFT_DIR)/libft.a
PRINTF  := $(PRINTF_DIR)/libftprintf.a

all:  libft printf $(NAME)
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -sC $(LIBFT_DIR)

printf:
	@make -sC $(PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC)  $(CFLAGS) $(OBJS) $(LIBS) $(LIBFT) $(PRINTF) $(HEADERS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)\n"

clean:
	@rm -rf $(OBJS)
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(PRINTF_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -sC $(LIBFT_DIR) fclean
	@make -sC $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libmlx libft printf

