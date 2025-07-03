# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 17:42:10 by kmoundir          #+#    #+#              #
#    Updated: 2025/04/11 14:00:08 by kmoundir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = zombieH

SRC = main.cpp zombieHorde.cpp Zombie.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(Name)
$(Name): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(Name)

clean:
	rm -f $(OBJ)
	

fclean: clean
	rm -f $(Name)

re : fclean all

.phony: all  fclean re