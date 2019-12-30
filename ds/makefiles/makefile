# Directories: 
DS_DIR =.
DS_SRC_DIR   = $(DS_DIR)/src#DS .c Files
DS_INC_DIR   = $(DS_DIR)/include#DS .h Files
DS_OBJ_DIR   = $(DS_DIR)/obj#DS .o Files
DS_TEST_DIR  = $(DS_DIR)/test#DS test Files
DS_BUILD_DIR = $(DS_DIR)/build#Executable File
DS_LIB_DIR   = $(DS_DIR)/lib#Libraries

# Compiler:
CC = gcc
GDFLAGS = -ansi -pedantic-errors -Wall -Wextra -g
GCFLAGS = -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
LDFLAGS = -shared 
PICFLAG = -fPIC
RPATH = -Wl,-rpath,"./lib"

#Output File Name
TARGET = output

REQ_OBJECTS =\
$(DS_OBJ_DIR)/doublelist.o\

REQ_SRC =\
$(DS_SRC_DIR)/doublelist/doublelist.c\

REQ_LIB =\
$(DS_LIB_DIR)/libdoublelist.so\

LIB_NAME = doublelist


# Combine Requiers Objects: 
OBJECTS = $(REQ_OBJECTS)

# Dependencies (for all objects):
DEPENDENCIES = $(OBJECTS:%.o=%.d)

# Build object: 
define COMPILE_OBJECT
@echo "\n\033[1;34mBuilding Objects $@: \033[0m"
@$(CC) $(GDFLAGS) $(PICFLAG) -c $< $(DS_SRC_DIR) -I$(DS_INC_DIR) -o $@
@echo "\033[0;32mDone. \033[0m"
endef

# Build object: 
define COMPILE_SHARED_LIB
@echo "\n\033[1;34mBuilding Shared Libraries $@: \033[0m"
@$(CC) $(LDFLAGS) $< -o $@
@echo "\033[0;32mDone. \033[0m"
endef

.PHONY: directories all output clean

all: directories output

-include $(DEPENDENCIES)

directories:
	@mkdir -p $(DS_BUILD_DIR) $(DS_OBJ_DIR)

output: $(REQ_OBJECTS) $(REQ_LIB)
	@echo "Compiling & linking $@..."
	@$(CC) $(GDFLAGS) $(DS_TEST_DIR)/doublelist_test.c -l$(LIB_NAME) -L./$(DS_LIB_DIR) $(RPATH) -I$(DS_INC_DIR) -o $(DS_BUILD_DIR)/$(TARGET)
	@echo "Compilation Successful!"

$(DS_OBJ_DIR)/doublelist.o: $(DS_SRC_DIR)/doublelist/doublelist.c $(DS_INC_DIR)/doublelist.h
	$(COMPILE_OBJECT)

$(DS_LIB_DIR)/libdoublelist.so: $(DS_OBJ_DIR)/doublelist.o
	$(COMPILE_SHARED_LIB)

clean: 
	@echo "\n\033[1;34mRemoving All Build files: \033[0m"
	rm -rf $(BUILD_DIR)/* $(OBJ_DIR)/* 
	@echo "\033[0;32mDone. \033[0m"