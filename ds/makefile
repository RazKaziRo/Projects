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
$(OBJ_DIR)/doublelist.o\
$(OBJ_DIR)/sortedlist.o\
$(OBJ_DIR)/priorityq.o

# Combine Requiers Objects: 
OBJECTS = $(REQ_OBJECTS)

# Dependencies (for all objects):
DEPENDENCIES = $(OBJECTS:%.o=%.d)

# Build object: 
define COMPILE_OBJECT
@echo "\n\033[1;34mBuilding $@: \033[0m"
$(CC) $(CFLAGS) -c $< -I$(SRC_DIR) -I$(H_DIR) -o $@
@echo "\033[0;32mDone. \033[0m"
endef

.PHONY: directories all output clean

all: directories output

-include $(DEPENDENCIES)

directories:
	mkdir -p $(BUILD_DIR) $(OBJ_DIR)

output: $(REQ_OBJECTS)
	@echo "\n\033[1;34mCompiling & linking $@: \033[0m"
	$(CC) $(CFLAGS) $(TEST_DIR)/priorityq_test.c -I$(H_DIR) $(REQ_OBJECTS) -o $(BUILD_DIR)/$(TARGET)
	@echo "\033[1;32mCompilation Successful. \033[0m"

$(OBJ_DIR)/doublelist.o: $(SRC_DIR)/doublelist/doublelist.c
	$(COMPILE_OBJECT)

$(OBJ_DIR)/sortedlist.o: $(SRC_DIR)/sortedlist/sortedlist.c
	$(COMPILE_OBJECT)

$(OBJ_DIR)/priorityq.o: $(SRC_DIR)/priorityq/priorityq.c
	$(COMPILE_OBJECT)

clean: 
	@echo "\n\033[1;34mRemoving All Build files: \033[0m"
	rm -rf $(BUILD_DIR)/* $(OBJ_DIR)/* 
	@echo "\033[0;32mDone. \033[0m"