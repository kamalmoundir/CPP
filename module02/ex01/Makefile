# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 19:40:00 by kmoundir          #+#    #+#              #
#    Updated: 2025/04/18 11:18:53 by kmoundir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = fixed

SRC = Fixed.cpp test_fixed.cpp

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

.phony: all clean fclean re