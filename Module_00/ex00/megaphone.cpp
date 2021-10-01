# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaripap <dsaripap@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/01 14:28:18 by dsaripap      #+#    #+#                  #
#    Updated: 2021/10/01 16:53:29 by dsaripap      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = clang++ 
CFLAGS = -Wall -Wextra -Werror -g

RED=\033[0;31m
GREEN=\033[0;32m
CYAN=\033[0;36m
NC=\033[0m # No Color

SRC = \
	megaphone.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${GREEN} [ + ] ${NC}Creating executable"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@echo "${GREEN} [ + ] ${NC}Creating all object files"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@echo "${RED} [ - ] ${NC}Deleting all object files"
	@rm -rf $(OBJ)

fclean: clean
	@echo "${RED} [ - ] ${NC}Deleting executable"
	@rm -rf $(NAME)

re: fclean all
