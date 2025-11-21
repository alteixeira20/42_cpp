# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 14:32:42 by alteixeira20      #+#    #+#              #
#    Updated: 2025/11/21 16:53:48 by alteixeira20     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC		= phonebook

# Directories
SRC_DIR		= src
OBJ_DIR		= obj

# Source Files
SRC		= $(SRC_DIR)/PhoneBook.cpp
SRC		+= $(SRC_DIR)/Contact.cpp
SRC		+= $(SRC_DIR)/Utils.cpp
SRC		+= $(SRC_DIR)/main.cpp

# Object Files
OBJS		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler & Flags
COMPILER	= c++
CFLAGS		= -Wall -Wextra -Werror -g -std=c++98

# Build Rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

all: $(EXEC)

$(EXEC): $(OBJS)
	@$(COMPILER) $(CFLAGS) $(OBJS) -o $(EXEC)
	@echo "$(B)PhoneBook$(D) compiled $(GRN)successfully$(D)"

# Cleaning Rules
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(B)Object files$(RED) removed$(D)"

fclean: clean
	@rm -f $(EXEC)
	@echo "$(B)Executable$(RED) removed$(D)"

re: fclean all

# **************************************************************************** #
#                                 Colors                                        #
# **************************************************************************** #

B   = $(shell tput bold)
RED = $(shell tput setaf 1)
GRN = $(shell tput setaf 2)
YEL = $(shell tput setaf 3)
D   = $(shell tput sgr0)
