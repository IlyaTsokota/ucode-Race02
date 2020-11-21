
NAME = way_home

SRC_DIR = src

INC_DIR = inc
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
CC = clang

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

RM = rm -rf

all: $(NAME) clean


$(NAME):
	@$(CC) $(CFLAGS) $(SRC_FILES) -I $(INC_DIR) -o $(NAME)
	@printf "\r\33[2K$@\t \033[32;1mcreated\033[0m\n"

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(OBJ_DIR) in $(NAME)\t \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@$(RM) $(NAME)
	@@printf "$(NAME)\t \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all

.PHONY: all uninstall clean reinstall
