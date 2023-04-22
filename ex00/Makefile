# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 11:07:21 by pfrances          #+#    #+#              #
#    Updated: 2023/04/22 17:07:32 by pfrances         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prgm
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -MMD -MP
INCLUDE = -I includes

SRCS_DIR = ./srcs
OBJS_DIR = ./objs
SRCS = $(addprefix $(SRCS_DIR)/,	main.cpp		\
									ScalarConverter.cpp)
OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)