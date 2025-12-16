# Program 
#
EXEC		= bsp

# Directories
SRC_DIR		= src
INC_DIR		= inc
OBJ_DIR		= obj

# Source Files
SRC		= $(SRC_DIR)/Fixed.cpp
SRC		+= $(SRC_DIR)/Point.cpp
SRC		+= $(SRC_DIR)/bsp.cpp
SRC		+= $(SRC_DIR)/main.cpp

# Object Files
OBJS		= $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Compiler & Flags
COMPILER	= c++
CFLAGS		= -Wall -Wextra -Werror -g -std=c++98 -I$(INC_DIR)

# Testing
# Default triangle used by main.cpp
AX = 0
AY = 0
BX = 10
BY = 0
CX = 5
CY = 10

# Run a single BSP test case
# $(1) = index
# $(2) = label
# $(3) = x
# $(4) = y
# $(5) = expected description
define BSP_TEST
	@echo "$(YEL)[$(1)] $(2)$(D)"
	@echo "  P = ($(3), $(4)): Expected: \
$(if $(findstring inside,$(5)),$(GRN)$(5)$(D),$(RED)$(5)$(D))"
	@./$(EXEC) $(3) $(4) | \
		sed -e 's/inside triangle/$(GRN)inside$(D) triangle/' \
		    -e 's/outside triangle/$(RED)outside$(D) triangle/'
	@echo
endef

# Build Rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

# Main Rule
all: $(EXEC)

$(EXEC): $(OBJS)
	@$(COMPILER) $(CFLAGS) $(OBJS) -o $(EXEC)
	@echo "$(B)bsp$(D) compiled $(GRN)successfully$(D)"

# Test
test: all
	@echo "$(B)=== BSP Automated Tests ===$(D)\n"
	@echo "$(B)Triangle used:$(D)"
	@echo "  A = ($(AX), $(AY))"
	@echo "  B = ($(BX), $(BY))"
	@echo "  C = ($(CX), $(CY))"
	@echo

	$(call BSP_TEST,1,INSIDE (center),5,5,inside)
	$(call BSP_TEST,2,OUTSIDE (far away),20,20,outside)
	$(call BSP_TEST,3,ON EDGE (AB),5,0,outside (edge))
	$(call BSP_TEST,4,ON EDGE (AC midpoint),2.5,5,outside (edge))
	$(call BSP_TEST,5,ON EDGE (BC midpoint),7.5,5,outside (edge))
	$(call BSP_TEST,6,ON VERTEX (A),0,0,outside (vertex))
	$(call BSP_TEST,7,ON VERTEX (B),10,0,outside (vertex))
	$(call BSP_TEST,8,ON VERTEX (C),5,10,outside (vertex))
	$(call BSP_TEST,9,NEGATIVE (outside),-5,-5,outside)
	$(call BSP_TEST,10,NEGATIVE X (outside),-1,5,outside)
	$(call BSP_TEST,11,NEAR EDGE (just above AB),5,0.1,inside)
	$(call BSP_TEST,12,NEAR VERTEX (near A),0.1,0.1,inside)

	@echo "$(B)=== End of tests ===$(D)"
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
