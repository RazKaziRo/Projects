# Directories: 
DS_DIR =../ds
DS_SRC_DIR = $(DS_DIR)/src#DS .c Files
DS_INC_DIR = $(DS_DIR)/include#DS .h Files
DS_OBJ_DIR = $(DS_DIR)/obj#DS .o Files

PROJECT_DIR = .
BUILD_DIR   = $(PROJECT_DIR)/build#Executable File
SRC_DIR     = $(PROJECT_DIR)/src#.c Files
OBJ_DIR     = $(PROJECT_DIR)/obj#.o Files
H_DIR       = $(PROJECT_DIR)/include#.h Files
TEST_DIR    = $(PROJECT_DIR)/test#test Files

# Compiler:
CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g

#Output File Name
TARGET = output

REQ_OBJECTS =\
$(OBJ_DIR)/fsa.o\

REQ_SRC =\
$(SRC_DIR)/fsa/fsa.c\


# Combine Requiers Objects: 
OBJECTS = $(REQ_OBJECTS)

# Dependencies (for all objects):
DEPENDENCIES = $(OBJECTS:%.o=%.d)

# Build object: 
define COMPILE_OBJECT
@echo "\n\033[1;34mBuilding $@: \033[0m"
@$(CC) $(CFLAGS) -c $< $(SRC_DIR) -I$(H_DIR) -o $@
@echo "\033[0;32mDone. \033[0m"
endef

.PHONY: directories all output clean

all: directories output

-include $(DEPENDENCIES)

directories:
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)

output: $(REQ_OBJECTS)
	@echo "Compiling & linking $@..."
	@$(CC) $(CFLAGS) $(TEST_DIR)/fsa_test.c $(REQ_SRC) -I$(H_DIR) -I$(DS_INC_DIR) -o $(BUILD_DIR)/$(TARGET)
	@echo "Compilation Successful!"

$(OBJ_DIR)/fsa.o: $(SRC_DIR)/fsa/fsa.c
	$(COMPILE_OBJECT)

clean: 
	@echo "\n\033[1;34mRemoving All Build files: \033[0m"
	rm -rf $(BUILD_DIR)/* $(OBJ_DIR)/* 
	@echo "\033[0;32mDone. \033[0m"