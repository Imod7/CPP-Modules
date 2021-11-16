# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaripap <dsaripap@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/02 16:27:21 by dsaripap      #+#    #+#                  #
#    Updated: 2021/11/16 18:04:22 by dsaripap      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = outer_galactic_phonebook
CC = clang++ 
CFLAGS = -Wall -Wextra -Werror -g -std=c++98 -pedantic

RED=\033[0;31m
GREEN=\033[0;32m
CYAN=\033[0;36m
NC=\033[0m # No Color

SRC = \
	main.cpp \
	Phonebook.class.cpp \
	Contact.class.cpp \

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${GREEN} [ + ] ${NC}Creating all object files"
	@echo "${GREEN} [ + ] ${NC}Creating executable"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	@echo "${RED} [ - ] ${NC}Deleting all object files"
	@rm -rf $(OBJ)

fclean: clean
	@echo "${RED} [ - ] ${NC}Deleting executable"
	@rm -rf $(NAME)

re: fclean all