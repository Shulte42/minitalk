# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 17:19:22 by bruda-si          #+#    #+#              #
#    Updated: 2024/06/17 17:24:08 by bruda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_CLIENT		=	client
NAME_SERVER		=	server

SRC_DIR			=	src/
OBJ_DIR			=	obj/

CC				=	cc
CFLAGS			=	-Werror -Wall -Wextra -g
RM				=	rm -rf

SRC_CLIENT		=	$(SRC_DIR)client.c	
SRC_SERVER		=	$(SRC_DIR)server.c

CLIENT_COMP		=	$(SRC_CLIENT)
SERVER_COMP		=	$(SRC_SERVER)

OBJ_CLIENT		=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(CLIENT_COMP))
OBJ_SERVER		=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SERVER_COMP))

all:				$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):		$(OBJ_CLIENT) 
					$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER):		$(OBJ_SERVER)
					$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) $(OBJ_DIR)

fclean:				clean
					@$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re:					fclean all

.PHONY:				all clean fclean re