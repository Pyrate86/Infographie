# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 15:35:12 by ghilbert          #+#    #+#              #
#    Updated: 2015/04/16 11:50:46 by ghilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= mlx_tools

BIN_PATH	= bin/
SRC_PATH	= ./
OBJ_PATH	= obj/
INC_PATH	= includes/

SRC_NAME	=	draw.c \
				hooks.c \
				img_cicrle.c \
				img_line.c \
				img_pixel.c \
				img_square.c \
				img_str.c \
				main.c \
				utils.c \
				win_circle.c \
				win_line.c \
				win_square.c

HEADER 		=	$(INC_PATH)mlx_tools.h \
				$(INC_PATH)colors.h \
				$(INC_PATH)keys.h

LIBX11		= -L%%%% -lXext -lX11

LIBMLX		= -Llibs -lmlx

OTHER_LIBS	= -lm

LIBS		= $(LIBMLX) $(LIBX11) $(OTHER_LIBS)

CC			= gcc
CFLAGS		+= -Wall -Werror -Wextra

SRC			= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJS 		= $(addprefix $(OBJ_PATH),$(subst .c,.o,$(SRC_NAME)))
BIN			= $(addprefix $(BIN_PATH),$(NAME))


.PHONY: all clean fclean re proper debug debugall

all:	$(BIN)

$(NAME): $(BIN)

$(BIN): $(OBJS) $(HEADER) | $(BIN_PATH)
	$(CC) $(CFLAGS) -I$(INC_PATH) $(OBJS) -o $(BIN) $(LIBS)

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
	rm -rf $(OBJS)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(BIN_PATH)

proper: all clean

re:	fclean all

debug:
	CFLAGS="-g" make

debugall:
	CFLAGS="-g" make re