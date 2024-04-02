CC = gcc
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = obj
APP = callback
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/console.o
LIBS = libs
all: allways build_app

allways:
	@printf "Creating Necessary Directories...\n"
	@printf "App name = \"%s\"\n" $(APP)
	@printf "Build Directory = \"%s\"\n" $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)
clean:
	@rm -rf $(OBJ_DIR)/*
$(OBJ_DIR)/main.o:$(SRC_DIR)/main.c
	@printf "Compiling...\n"
	@$(CC) -c $^  -o $@
$(OBJ_DIR)/console.o:$(SRC_DIR)/console.c
	@printf "Compiling...\n"
	@$(CC) -c $^  -o $@
make_objs: $(OBJS)
build_app:clean make_objs
	@printf "Linking All Objects Together...\n"
	$(CC)  $(OBJS) -I $(LIBS) -o $(BUILD_DIR)/$(APP)
