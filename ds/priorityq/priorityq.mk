#Hash Makefile

# Directories: 
DIR :=.
INC_DIR   := ../include#DS .h Files
OBJ_DIR   := $(DIR)/obj#DS .o Files
LIB_DIR   := ../lib#Libraries
TEST_DIR  := ../../tests#Libraries

# Compiler:
CC = gcc
DEBUGFLAGS = -ansi -pedantic-errors -Wall -Wextra -g
RCFLAGS = -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
LDFLAGS = -shared 
PICFLAG = -fpic
RPATH = -Wl,-rpath,'$$ORIGIN/../lib'

#File Names:
NAME = priorityq_sll

#Dependencies Files
DEPENDENCIES = sortedlist

.PHONY: all clean directories 

all: directories debug 

directories:
	@mkdir -p $(OBJ_DIR) $(LIB_DIR)

debug: $(NAME) $(LIB_DIR)/lib$(NAME).so

$(NAME): $(OBJ_DIR)/$(NAME).o $(LIB_DIR)/lib$(NAME).so
	@$(CC) $(DEBUGFLAGS) $(TEST_DIR)/$(NAME)_test.c -L$(LIB_DIR) $(RPATH) -I$(INC_DIR) -o $@ -l$(NAME) -l$(DEPENDENCIES) -ldoublelist

$(OBJ_DIR)/$(NAME).o: $(NAME).c $(INC_DIR)/$(NAME).h
	@$(CC) $(DEBUGFLAGS) -c $(PICFLAG) -I$(INC_DIR) $(NAME).c -o $@ 

$(LIB_DIR)/lib$(NAME).so: $(OBJ_DIR)/$(NAME).o $(LIB_DIR)/lib$(DEPENDENCIES).so $(LIB_DIR)/libdoublelist.so
	@$(CC) $(LDFLAGS) -o $@ $(OBJ_DIR)/$(NAME).o 

$(LIB_DIR)/lib$(DEPENDENCIES).so:
	cd ../$(DEPENDENCIES) && make -f $(DEPENDENCIES).mk

$(LIB_DIR)/libdoublelist.so:
	cd ../doublelist && make -f doublelist.mk

clean: remove_dir clean_dependencies
	rm $(OBJ_DIR)/*.o $(LIB_DIR)/lib$(NAME).so

remove_dir:
	rm -r $(OBJ_DIR) $(LIB_DIR) $(NAME)

clean_dependencies:
	cd ../$(DEPENDENCIES) && make -f $(DEPENDENCIES).mk clean

