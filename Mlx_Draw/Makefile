# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 15:35:12 by ghilbert          #+#    #+#              #
#    Updated: 2015/04/21 16:49:41 by ghilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= mlx_tools

BIN_PATH	= bin/
SRC_PATH	= ./
OBJ_PATH	= obj/
INC_PATH	= includes/

SRC_NAME	=	alpha_mask.c \
				draw.c \
				ft_maths.c \
				hooks.c \
				img_cicrle.c \
				img_image.c \
				img_line.c \
				img_pixel.c \
				img_polygone.c \
				img_rotation.c \
				img_square.c \
				img_str.c \
				init_path.c \
				intersect.c \
				luminosity.c \
				main.c \
				opacity.c \
				utils.c \
				win_circle.c \
				win_line.c \
				win_polygone.c \
				win_square.c

HEADER 		=	$(INC_PATH)colors.h \
				$(INC_PATH)defines.h \
				$(INC_PATH)includes.h \
				$(INC_PATH)keys.h \
				$(INC_PATH)mlx_tools.h \
				$(INC_PATH)structs.h

LIBFT_PATH	= libft
LIBFT_NAME	= -lft
LIBFT		= -L$(LIBFT_PATH) $(LIBFT_NAME)

LIBX_NAME	= -lmlx -framework OpenGL -framework AppKit

OTHER_LIBS	= -lm

LIBX		= $(LIBX_NAME)

LIBS		= $(LIBFT) $(LIBX) $(OTHER_LIBS)


CC			= gcc
CFLAGS		+= -Wall -Werror -Wextra

SRC			= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJS 		= $(addprefix $(OBJ_PATH),$(subst .c,.o,$(SRC_NAME)))
BIN			= $(addprefix $(BIN_PATH),$(NAME))


.PHONY: all clean fclean re proper debug debugall libft

all:	$(BIN)

$(NAME): $(BIN)

$(BIN): $(OBJS) $(HEADER) libft/libft.a | $(BIN_PATH)
	$(CC) $(CFLAGS) -I$(INC_PATH) $(OBJS) -o $(BIN) $(LIBS)

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
	rm -rf $(BIN_PATH)

proper: all clean

re:	fclean all

debug:
	CFLAGS="-g" make

debugall:
	CFLAGS="-g" make re