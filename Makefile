MAKEFLAGS += --silent

NAME		=	cub3d
INC			=	inc/
HEADER		=	-I inc
SRC_DIR		=	src/
OBJ_DIR		=	obj/
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -g3
MLXFLAGS	= 	-L ./lib/minilibx -lmlx -Ilmlx_linux -lXext -lX11 -lbsd
LIBFT		=	lib/libft
MINILIBX	=	lib/minilibx
RM 			=	rm -rf
ECHO 		=	echo

#Colors
DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

MAIN_DIR 	=	main/
MAIN_FILES	=	miniCub3d

SRC_MAI_FILE=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))

MSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_MAI_FILE)))
MOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAI_FILE)))

OBJF 		= 	.cache_exists

OBJ 		=	$(MOBJ)

all: ${NAME}

${NAME}: $(OBJ)
				@make -C $(MINILIBX)
				@make -C $(LIBFT)
				$(CC) $(FLAGS) $(OBJ) $(HEADER) $(MLXFLAGS) lib/libft/libft.a lib/minilibx/libmlx.a -o $(NAME)
				@$(ECHO) "$(YELLOW)[CUB3D]:\t$(ORANGE)[==========]\t$(GREEN) => Success!$(DEF_COLOR)\n"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(OBJF)
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):		
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)$(MAIN_DIR)
				@touch $(OBJF)

help: ## Print help on Makefile.
				@grep '^[^.#]\+:\s\+.*#' Makefile | \
				sed "s/\(.\+\):\s*\(.*\) #\s*\(.*\)/`printf "$(GRAY)"`\1`printf "$(DEF_COLOR)"`	\3 /" | \
				expand -t8

clean: ## Clean generated files and cache.
				@$(RM) $(OBJ_DIR)
				@$(RM) $(OBJF)
				@$(RM) libft/obj
				@$(ECHO) "$(BLUE)[CUB3D]:\tobject files$(DEF_COLOR)\t$(GREEN) => Cleaned!$(DEF_COLOR)\n"

fclean: ## Clean all generated file, including binaries.	
				@make clean
				@$(RM) $(NAME)
				@$(RM) libft.a
				@$(RM) libmlx.a
				@make fclean -C $(LIBFT)
				@make clean -C $(MINILIBX)
				@$(ECHO) "$(CYAN)[CUB3D]:\texec. files$(DEF_COLOR)\t$(GREEN) => Cleaned!$(DEF_COLOR)\n"

re: ## Clean and rebuild binary file.
				@make fclean all
				@$(ECHO) "\n$(GREEN)###\tCleaned and rebuilt everything for [CUB3D]!\t###$(DEF_COLOR)\n"

.PHONY: all clean fclean re
