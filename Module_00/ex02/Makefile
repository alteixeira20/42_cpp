# Program

EXEC        = account

# Directories
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = inc

# Source Files
SRC         = $(SRC_DIR)/Account.cpp
SRC        += $(SRC_DIR)/tests.cpp

# Object Files
OBJS        = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Compiler & Flags
COMPILER    = clang++
CFLAGS      = -Wall -Wextra -Werror -g -std=c++98 -I$(INC_DIR)

# Build Rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

all: $(EXEC)

$(EXEC): $(OBJS)
	@$(COMPILER) $(CFLAGS) $(OBJS) -o $(EXEC)
	@echo "$(B)Account$(D) compiled $(GRN)successfully$(D)"

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
