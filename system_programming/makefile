# Directories: 
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
$(OBJ_DIR)/uid.o

REQ_SRC =\
$(SRC_DIR)/uid/uid.c

# Combine Requiers Objects: 
OBJECTS = $(REQ_OBJECTS)

# Dependencies (for all objects):
DEPENDENCIES = $(OBJECTS:%.o=%.d)

# Build object: 
define COMPILE_OBJECT
@echo "\n\033[1;31mBuilding $@: \033[0m"
@$(CC) $(CFLAGS) -c $< -I$(SRC_DIR) -I$(H_DIR) -o $@
@echo "\033[0;32mDone. \033[0m"
endef

.PHONY: directories all output clean

all: directories output

-include $(DEPENDENCIES)

directories:
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)

output: $(REQ_OBJECTS)
	@echo "Compiling & linking $@..."
	@$(CC) $(CFLAGS) $(TEST_DIR)/uid_test.c $(REQ_SRC) -I$(H_DIR) -o $(BUILD_DIR)/$(TARGET)
	@echo "Compilation Successful!"

$(OBJ_DIR)/uid.o: $(SRC_DIR)/uid/uid.c
	$(COMPILE_OBJECT)

clean: 
	@echo "\n\033[1;34mRemoving All Build files: \033[0m"
	rm -rf $(BUILD_DIR)/* $(OBJ_DIR)/* 
	@echo "\033[0;32mDone. \033[0m"