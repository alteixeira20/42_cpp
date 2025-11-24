# Program 
#
EXEC		= op_sed

# Directories
SRC_DIR		= src
OBJ_DIR		= obj

# Source Files
SRC		= $(SRC_DIR)/main.cpp

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
	@echo "$(B)OP Sed$(D) compiled $(GRN)successfully$(D)"

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
