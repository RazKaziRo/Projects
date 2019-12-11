# Directories: 
PROJECT_DIR = .
BUILD_DIR	= $(PROJECT_DIR)/build   #Executable File
SRC_DIR		= $(PROJECT_DIR)/src 	 #.c Files
OBJ_DIR		= $(PROJECT_DIR)/obj 	 #.o Files

# Compiler: 
CC= gcc 
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g

# Include Directories: 
INCLUDE_DIRS = -I`find -L $(SRC_DIR) -type d | sed 's/^/-I/'`

REQ_OBJECTS =				\
$(OBJ_DIR)/doublelist.o		\
$(OBJ_DIR)/sortedlist.o	

# Combine Requiers Objects: 
OBJECTS = $(REQ_OBJECTS)

# Dependencies (for all Objects): 
DEPENDENCIES = $(OBJECTS:%.o=%.d)

# Build object: 
define COMPILE_OBJECT
@echo "\n\033[1;34mBuilding $@: \033[0m"
$(CC) $(CFLAGS) -c $@ $< $(INCLUDE_DIRS) -o $@
@echo "\033[0;32mDone. \033[0m"
endef

.PHONY: directories all project clean

all: directories project 

-include $(DEPENDENCIES)

directories:
	mkdir -p $(BUILD_DIR)

project: $(OBJECTS)
	@echo "\n\033[1;34mCompiling & linking $@: \033[0m"
	$(CC) $(CFLAGS) $(OBJECTS) $(SRC_DIR)main.c $(INCLUDE_DIRS) -o $(BUILD_DIR)
	@echo "\033[1;32mCompilation successful. \033[0m"

$(BUILD_DIR)/doublelist.o: $(SRC_DIR)/doublelist.c
	$(COMPILE_OBJECT)	
	
$(BUILD_DIR)/sortedlist.o: $(SRC_DIR)/sortedlist.c
	$(COMPILE_OBJECT)

clean: 
	@echo "\n\033[1;34mRemoving All build files: \033[0m"
	rm -rf $(BUILD_DIR)/*
	@echo "\033[0;32mDone. \033[0m"