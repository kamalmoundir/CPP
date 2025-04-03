# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 16:18:35 by kmoundir          #+#    #+#              #
#    Updated: 2025/04/03 16:19:02 by kmoundir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = harlFilter

SRC = main.cpp Harl.cpp
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