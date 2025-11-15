CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
CLANG_DIR=..
COMMON_DIR=../common

all: clangcpp s21_cat

clangcpp:
	cp $(CLANG_DIR)/.clang-format . 
	clang-format -i *.c *.h $(COMMON_DIR)/*.c $(COMMON_DIR)/*.h
	cppcheck *.c *.h
	rm .clang-format

s21_cat: main.c cat.c $(COMMON_DIR)/common.c
	$(CC) $(CFLAGS) $^ -o s21_cat

debug: main.c cat.c $(COMMON_DIR)/common.c
	$(CC) $(CFLAGS) $^ -o s21_cat
	gdb ./s21_cat

clean: 
	rm s21_cat

test: 
	bash GODDESS_TEST.sh

valgrind: s21_cat
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$< -bEnsT *.txt | grep -ie leak -e error

rebuild: clean all
