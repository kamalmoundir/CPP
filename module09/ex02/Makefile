# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 15:10:29 by kmoundir          #+#    #+#              #
#    Updated: 2025/06/28 15:42:40 by kmoundir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = PmergeMe
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = main.cpp PmergeMe.cpp

# Object directory and files
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# Default target
all: $(NAME)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile source files to object files
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create executable
$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re