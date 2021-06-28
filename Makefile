.PHONY: all clean fclean re libft libbdlst create_dir
.SILENT: libft libbdlst

NAME			= push_swap
LIBFT_NAME		= libft.a
LIBBDLST_NAME	= libbdlst.a


######################### CC && FLAGS ########################

CC		= gcc 	# clang
DEBUG	= -g 	# -fsanitize=address

CFLAGS	= -Wall -Wextra -Werror

LIBFT_FLAGS		= -L $(LFT_DIR) -lft
LIBBDLST_FLAGS	= -L $(LBDLST_DIR) -lbdlst
INCLUDE_FLAGS 	= -I $(INC_DIR) -I $(LFT_DIR) -I $(LBDLST_DIR)

######################### DIRECTORIES ########################

SRC_DIR		= .
OBJ_DIR		= obj
LFT_DIR		= libft
INC_DIR		= .
LBDLST_DIR	= libbdlst

######################### SOURCES ############################

SOURCES			=	main.c \
					utils.c \
					instructions.c \
					init.c

HEADER_FILES	=	push_swap.h

######################## OBJECT FILES ########################

OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

######################## HEADERS #############################

HEADERS = $(addprefix $(INC_DIR)/, $(HEADER_FILES))

######################## INSTRUCTIONS ########################


all: libft libbdlst create_dir $(NAME)

create_dir:
	@mkdir -p $(OBJ_DIR)

libft:
	@$(MAKE) -C $(LFT_DIR) bonus

libbdlst:
	@$(MAKE) -C $(LBDLST_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) $(GNL_OBJ)
	@$(CC) $(DEBUG) $(CFLAGS) -c $< $(INCLUDE_FLAGS) $() -o $@

$(NAME): $(OBJECTS) $(HEADERS)
	@$(CC) $(DEBUG) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAGS) $(LIBBDLST_FLAGS) -o $@ 
	@echo "${NAME} created."

clean:
	@$(MAKE) clean -C $(LFT_DIR) --no-print-directory
	@$(MAKE) clean -C $(LBDLST_DIR) --no-print-directory 
	@rm -rf $(OBJ_DIR)/*.o

fclean: clean
	@$(MAKE) fclean -C $(LFT_DIR) --no-print-directory
	@$(MAKE) fclean -C $(LBDLST_DIR) --no-print-directory
	@rm -rf ${NAME}
	@echo "${NAME} has been deleted."

re: fclean all