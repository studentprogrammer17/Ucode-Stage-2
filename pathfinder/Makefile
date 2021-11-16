NAME = pathfinder.a
NAMEBIN = pathfinder

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = libmx

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))
INC_FILES = $(wildcard $(INC_DIR)/*.h)
LIB_FILES = $(wildcard $(LIB_DIR)/$(LIB_DIR).a)
LIB_INC_FILES = $(wildcard $(LIB_DIR)/$(INC_DIR))

CC = clang
CFLAGS = -std=c11 $(addprefix -W, all extra error pedantic) -g
AR = ar
AFLAGS = rcs
MAKE = make -C

MKDIR = mkdir -p
RM = rm -rf

all: $(NAMEBIN) clean

$(NAMEBIN): $(OBJ_FILES)
	@$(MAKE) $(LIB_DIR)
	@$(CC) $(CFLAGS) $^ -L$(LIB_DIR) -lmx -o $@
	@printf "\r\33[2K$@\t \033[32;1mcreated\033[0m\n"

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIB_INC_FILES)
	@printf "\r\33[2K$(NAME)\033[33;1m\t compile \033[0m$(<:$(SRC_DIR)/%.c=%)\r"

$(OBJ_DIR):
	@$(MKDIR) $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(LIB_FILES)
	@printf "$(OBJ_DIR) in $(NAME)\t \033[31;1mdeleted\033[0m\n"

uninstall:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAMEBIN)
	@@printf "$(NAME)\t \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all

.PHONY: all uninstall clean reinstall

