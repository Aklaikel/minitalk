# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 12:45:06 by aklaikel          #+#    #+#              #
#    Updated: 2021/12/18 18:25:33 by aklaikel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


INC = mylibrary.h

SERVER_SRCS = server.c srcs/myprint.c
CLIENT_SRCS = client.c srcs/ft_atoi.c srcs/myprint.c

SERVER_SRCS_BONUS = server_bonus.c srcs/myprint.c
CLIENT_SRCS_BONUS = client_bonus.c srcs/ft_atoi.c srcs/myprint.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_OBJS_BONUS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf 

all: server client server_bonus client_bonus

bonus: server_bonus client_bonus

client:$(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) -o client
	@echo "client created successfully"

server:$(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) -o server
	@echo "serverbonus created successfully"

client_bonus:$(CLIENT_OBJS_BONUS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS_BONUS) -o client_bonus
	@echo "client bonus created successfully"

server_bonus:$(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) -o server_bonus
	@echo "server bonus created successfully"

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	@echo "object files removed successfully"
	@echo "object bonus files removed successfully"

fclean:clean
	@$(RM) client server client_bonus server_bonus
	@echo "client/client_bonus and server/server_bonus removed successfully"

re: fclean all