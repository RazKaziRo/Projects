#BitsArray Makefile

# Directories: 
DIR :=.
INC_DIR   := ../include#DS .h Files
OBJ_DIR   := $(DIR)/obj#DS .o Files
BUILD_DIR := $(DIR)/build#Executable File
LIB_DIR   := ../lib#Libraries


# Compiler:
CC = gcc
DEBUGFLAGS = -ansi -pedantic-errors -Wall -Wextra -g
RCFLAGS = -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
LDFLAGS = -shared 
PICFLAG = -fpic
RPATH = -Wl,-rpath,'$$ORIGIN/../../lib'

#File Names:
NAME = stack

.PHONY: all clean directories 

all: directories debug

directories:
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)

debug: $(BUILD_DIR)/$(NAME)_debug $(LIB_DIR)/lib$(NAME)_debug.so

release: $(BUILD_DIR)/$(NAME)_rc $(LIB_DIR)/lib$(NAME)_rc.so

#Debug ------------------------------------------------------------
$(BUILD_DIR)/$(NAME)_debug: $(OBJ_DIR)/$(NAME)_debug.o $(LIB_DIR)/lib$(NAME)_debug.so $(NAME)_test.c
	@$(CC) $(DEBUGFLAGS) $(NAME)_test.c -l$(NAME)_debug -L$(LIB_DIR) $(RPATH) -I$(INC_DIR) -o $@

$(OBJ_DIR)/$(NAME)_debug.o: $(NAME).c $(INC_DIR)/$(NAME).h
	@$(CC) $(DEBUGFLAGS) -c $(PICFLAG) -I$(INC_DIR) $(NAME).c -o $@ 

$(LIB_DIR)/lib$(NAME)_debug.so: $(OBJ_DIR)/$(NAME)_debug.o
	@$(CC) $(LDFLAGS) -o $@ $(OBJ_DIR)/$(NAME)_debug.o

#Release ---------------------------------------------------------

$(BUILD_DIR)/$(NAME)_rc: $(OBJ_DIR)/$(NAME)_rc.o $(LIB_DIR)/lib$(NAME)_rc.so
	@$(CC) $(RCFLAGS) $(NAME)_test.c -l$(NAME)_rc -L$(LIB_DIR) $(RPATH) -I$(INC_DIR) -o $@

$(OBJ_DIR)/$(NAME)_rc.o: $(NAME).c $(INC_DIR)/$(NAME).h
	@$(CC) $(RCFLAGS) -c -c $(PICFLAG) -I$(INC_DIR) $(NAME).c -o $@ 

$(LIB_DIR)/lib$(NAME)_rc.so: $(OBJ_DIR)/$(NAME)_rc.o
	@$(CC) $(LDFLAGS) -o $@ $(OBJ_DIR)/$(NAME)_rc.o

clean:
	rm $(OBJ_DIR)/*.o $(BUILD_DIR)/* $(LIB_DIR)/lib$(NAME)_rc.so $(LIB_DIR)/lib$(NAME)_debug.so