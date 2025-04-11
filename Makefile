# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 19:58:00 by ticasali          #+#    #+#              #
#    Updated: 2025/04/07 23:58:59 by ticasali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C		=			client

NAME_S		=			server

DIR_SRCS_C	=			Client/src

DIR_SRCS_S	=			Server/src

SRCS_C 		=			$(DIR_SRCS_C)/main_client.c		\
						$(DIR_SRCS_C)/atoi.c			\
						$(DIR_SRCS_C)/client.c			\
						$(DIR_SRCS_C)/error_client.c

SRCS_S =				$(DIR_SRCS_S)/main_server.c		\
						$(DIR_SRCS_S)/putnbr.c			\
						$(DIR_SRCS_S)/server.c			\
						$(DIR_SRCS_S)/error_server.c	\
						$(DIR_SRCS_S)/dynamic_array.c

DIR_OBJS_C =			.objs_c

DIR_OBJS_S =			.objs_s

OBJS_C =				$(SRCS_C:$(DIR_SRCS_C)/%.c=$(DIR_OBJS_C)/%.o)

OBJS_S =				$(SRCS_S:$(DIR_SRCS_S)/%.c=$(DIR_OBJS_S)/%.o)

CFLAGS =				-Wall -Wextra -Werror

all:					$(NAME_C) $(NAME_S)

$(DIR_OBJS_C)/%.o:		$(DIR_SRCS_C)/%.c Client/include/client.h
						@mkdir -p $(dir $@)
						$(CC) $(CFLAGS) -c $< -o $@ -I./Client/include

$(DIR_OBJS_S)/%.o:		$(DIR_SRCS_S)/%.c Server/include/server.h
						@mkdir -p $(dir $@)
						$(CC) $(CFLAGS) -c $< -o $@ -I./Server/include

$(NAME_C):				$(OBJS_C)
						$(CC) $(CFLAGS) -o $@ $^ -I./Client/include

$(NAME_S):				$(OBJS_S)
						$(CC) $(CFLAGS) -o $@ $^ -I./Server/include

clean:
						$(RM) -r $(DIR_OBJS_S) $(DIR_OBJS_C)

fclean:					clean
						$(RM) $(NAME_C) $(NAME_S)

re:						fclean
						$(MAKE) all

.PHONY:					all clean fclean re