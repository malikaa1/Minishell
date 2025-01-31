# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 10:45:55 by ybesbes           #+#    #+#              #
#    Updated: 2021/12/02 22:21:51 by mrahmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= minishell

SRCS		= main.c check.c parsing.c pipe.c pwd.c free.c parse.c mini_split.c cd.c echo.c env.c \
				putfile.c export.c unset.c signal.c export_utils.c pipe_utils.c parse_utils.c exit.c

INCLUDES	=	include

LIBFT_DIR 	= libft

SRCS_LIBFT 	= ${wildcard libft/*.c}

OBJS_LIBFT	= ${SRCS_LIBFT:.c=.o}

OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

CFLAGS		= -g -Wall -Wextra -Werror 

.c.o:
				${CC} ${CFLAGS} -c -I ${INCLUDES} $< -o ${<:.c=.o}


all: 			${NAME}

${NAME}:	$(OBJS) $(OBJS_LIBFT)
			@$(CC) $(CFLAGS) -g -I $(INCLUDES) $(OBJS) $(OBJS_LIBFT) -I/usr/include/readline -lreadline -o $(NAME)


clean:
				@make clean -C $(LIBFT_DIR)
				${RM} ${OBJS} 

fclean:			clean
				@make fclean -C $(LIBFT_DIR)
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
