# Directories: 
DIR =.
INC_DIR   = ../include#DS .h Files
OBJ_DIR   = $(DIR)/obj#DS .o Files
BUILD_DIR = $(DIR)/build#Executable File
LIB_DIR   = ../lib#Libraries

# Compiler:
CC = gcc
DEBUGFLAGS = -ansi -pedantic-errors -Wall -Wextra -g
RCFLAGS = -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
LDFLAGS = -shared 
PICFLAG = -fpic
RPATH = -Wl,-rpath,"../$(LIB_DIR)"

#File Names:
NAME = sortedlist

.PHONY: all clean directories 

all: $(BUILD_DIR) $(OBJ_DIR) debug

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

debug: $(BUILD_DIR)/$(NAME)_debug $(LIB_DIR)/lib$(NAME)_debug.so

release: $(BUILD_DIR)/$(NAME)_rc $(LIB_DIR)/lib$(NAME)_rc.so

#Debug ------------------------------------------------------------

$(BUILD_DIR)/$(NAME)_debug: $(OBJ_DIR)/$(NAME)_debug.o $(LIB_DIR)/lib$(NAME)_debug.so | 
	$(CC) $(DEBUGFLAGS) $(NAME)_test.c  -L$(LIB_DIR) -Wl,-rpath,'$$ORIGIN/../../lib' -I$(INC_DIR) -o $@ -l$(NAME)_debug

$(OBJ_DIR)/$(NAME)_debug.o: $(NAME).c $(INC_DIR)/$(NAME).h
	$(CC) $(DEBUGFLAGS) -c $(PICFLAG) -I$(INC_DIR) $(NAME).c -o $@ 

$(LIB_DIR)/lib$(NAME)_debug.so: $(OBJ_DIR)/$(NAME)_debug.o
	$(CC) $(LDFLAGS) -o $@ $(OBJ_DIR)/$(NAME)_debug.o -L$(LIB_DIR) -Wl,-rpath,'$$ORIGIN' -ldoublelist_debug

#Release ---------------------------------------------------------

$(BUILD_DIR)/$(NAME)_rc: $(OBJ_DIR)/$(NAME)_rc.o $(LIB_DIR)/lib$(NAME)_rc.so 
	$(CC) $(RCFLAGS) $(NAME)_test.c  -L$(LIB_DIR) -Wl,-rpath,'$$ORIGIN/../../lib' -I$(INC_DIR) -o $@ -l$(NAME)_debug

$(OBJ_DIR)/$(NAME)_rc.o: $(NAME).c $(INC_DIR)/$(NAME).h
	$(CC) $(RCFLAGS) -c $(PICFLAG) -I$(INC_DIR) $(NAME).c -o $@ 

$(LIB_DIR)/lib$(NAME)_rc.so: $(OBJ_DIR)/$(NAME)_rc.o
	$(CC) $(LDFLAGS) -o $@ $(OBJ_DIR)/$(NAME)_rc.o -L$(LIB_DIR) -Wl,-rpath,'$$ORIGIN' -ldoublelist_rc

clean:
	rm $(OBJ_DIR)/*.o $(BUILD_DIR)/* $(LIB_DIR)/lib$(NAME)_rc.so $(LIB_DIR)/lib$(NAME)_debug.so