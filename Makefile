# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 14:46:16 by cpothin           #+#    #+#              #
#    Updated: 2023/11/08 08:47:32 by acharlot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
MAIN_FILES	=	cub3d  game panic
REND_DIR 	=	render/
REND_FILES	=	raycasting render  image 
MENU_DIR 	=	menu/
MENU_FILES	=	menu init_menus unload highlight_buttons menu_utils
INIT_DIR	= 	init/
INIT_FILES	=	init_mlx init_player_pov init init_minimap
PARS_DIR	=	parsing/
PARS_FILES	=	parsing parsing_utils
MMAP_DIR	=	minimap/
MMAP_FILES	=	minimap minimap_utils
INPU_DIR	=	inputs/
INPU_FILES	=	inputs press_in move_player


SRC_MAI_FILE=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))
SRC_REN_FILE=	$(addprefix $(REND_DIR), $(REND_FILES))
SRC_MEN_FILE=	$(addprefix $(MENU_DIR), $(MENU_FILES))
SRC_INI_FILE=	$(addprefix $(INIT_DIR), $(INIT_FILES))
SRC_PAR_FILE=	$(addprefix $(PARS_DIR), $(PARS_FILES))
SRC_MAP_FILE=	$(addprefix $(MMAP_DIR), $(MMAP_FILES))
SRC_INP_FILE=	$(addprefix $(INPU_DIR), $(INPU_FILES))

MAINSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_MAI_FILE)))
MAINOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAI_FILE)))

RENDSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_REN_FILE)))
RENDOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_REN_FILE)))

MENUSRC		=	$(addprefix $(MENU_DIR), $(addsuffix .c, $(SRC_MEN_FILE)))
MENUOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MEN_FILE)))

INITSRC		=	$(addprefix $(INIT_DIR), $(addsuffix .c, $(SRC_INI_FILE)))
INITOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_INI_FILE)))

PARSSRC		=	$(addprefix $(PARS_DIR), $(addsuffix .c, $(SRC_PAR_FILE)))
PARSOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_PAR_FILE)))

MMAPSRC		=	$(addprefix $(MMAP_DIR), $(addsuffix .c, $(SRC_MAP_FILE)))
MMAPOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAP_FILE)))

INPUSRC		=	$(addprefix $(INPU_DIR_DIR), $(addsuffix .c, $(SRC_INP_FILE)))
INPUOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_INP_FILE)))


OBJF 		= 	.cache_exists

OBJ 		=	$(MAINOBJ) $(MENUOBJ) $(RENDOBJ) $(INITOBJ) $(PARSOBJ) $(MMAPOBJ) $(INPUOBJ)

all: ${NAME}

${NAME}: $(OBJ)
				@make -C $(MINILIBX)
				@make -C $(LIBFT)
				$(CC) $(FLAGS) $(OBJ) $(HEADER) $(MLXFLAGS) lib/libft/libft.a lib/minilibx/libmlx.a -lm -o $(NAME)
				@$(ECHO) "$(YELLOW)[CUB3D]:\t$(ORANGE)[==========]\t$(GREEN) => Success!$(DEF_COLOR)\n\e[?25h"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(OBJF)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO) -n "\e[?25l\r\033[K$< created"

$(OBJF):		
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)$(MAIN_DIR)
				@mkdir -p $(OBJ_DIR)$(REND_DIR)
				@mkdir -p $(OBJ_DIR)$(MENU_DIR)
				@mkdir -p $(OBJ_DIR)$(INIT_DIR)
				@mkdir -p $(OBJ_DIR)$(PARS_DIR)
				@mkdir -p $(OBJ_DIR)$(MMAP_DIR)
				@mkdir -p $(OBJ_DIR)$(INPU_DIR)
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

.PHONY: all clean fclean re help
