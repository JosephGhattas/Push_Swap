NAME = push_swap

LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a  
SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
FT_PRINTF_DIR = ./ft_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HLIBFT) $(HFT_PRINTF)
HLIBFT = -I ./libft
HFT_PRINTF = -I$(FT_PRINTF_DIR)  

SRC = $(SRC_DIR)handle_errors.c \
	$(SRC_DIR)init_a_to_b.c \
	$(SRC_DIR)init_b_to_a.c \
	$(SRC_DIR)main.c \
	$(SRC_DIR)push.c \
	$(SRC_DIR)reverse_rotate.c \
	$(SRC_DIR)rotate.c \
	$(SRC_DIR)sort_three.c \
	$(SRC_DIR)sort.c \
	$(SRC_DIR)split.c \
	$(SRC_DIR)stack_utils.c \
	$(SRC_DIR)stack_init.c \
	$(SRC_DIR)swap.c \
	$(SRC_DIR)rotate2.c \
	$(SRC_DIR)free.c

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

FT_PRINTF_OBJ = $(FT_PRINTF_DIR)/libftprintf.o  

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME) -g

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C ./libft clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(LIBFT) $(FT_PRINTF)
	make -C ./libft fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all
