# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 15:35:12 by ghilbert          #+#    #+#              #
#    Updated: 2014/11/29 15:35:14 by ghilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= wolf3d

BIN_PATH	= bin/
SRC_PATH	= ./
OBJ_PATH	= obj/
INC_PATH	= includes/

SRC_NAME	=	affich.c \
				dialog.c \
				event.c \
				floor.c \
				funcs.c \
				get_map.c \
				get_next_line.c \
				hook.c \
				init.c \
				main.c \
				map.c \
				ray.c \
				skybox.c \
				structs.c \
				textures.c \
				xdraw.c

HEADER 		= $(INC_PATH)wolf.h

LIBX_PATH	= /usr/X11/lib
LIBX_NAME	= -lmlx -lXext -lx11
LIBFT_PATH	= libft
LIBFT_NAME	= -lft
OTHER_LIBS	= -lm
LIBX		= -L$(LIBX_PATH) $(LIBX_NAME)
LIBFT		= -L$(LIBFT_PATH) $(LIBFT_NAME)
LIBS		= $(LIBFT) $(LIBX) $(OTHER_LIBS)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRC			= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJS 		= $(addprefix $(OBJ_PATH),$(subst .c,.o,$(SRC_NAME)))
BIN			= $(addprefix $(BIN_PATH),$(NAME))



.PHONY: all clean fclean re proper libft

all:	$(BIN)

$(BIN): $(OBJS) $(HEADER) libft/libft.a | $(BIN_PATH)
	$(CC) $(CFLAGS) -I$(INC_PATH) $(LIBS) $(OBJS) -o $(BIN)

libft/libft.a:
	make -C libft

$(OBJS): | $(OBJ_PATH)

$(OBJ_PATH)%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@ -I $(INC_PATH)

$(OBJ_PATH):
	@if [ ! -d "$(OBJ_PATH)" ]; then \
		mkdir $(OBJ_PATH);\
		fi

$(BIN_PATH):
	@if [ ! -d "$(BIN_PATH)" ]; then \
		mkdir $(BIN_PATH);\
		fi

clean:
	@make clean -C libft
	rm -rf $(OBJS)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

proper: all clean

re:	fclean all
