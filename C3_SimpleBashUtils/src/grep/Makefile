CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
CLANG_DIR=..
COMMON_DIR=../common

all: clangcpp s21_grep

clangcpp:
	cp $(CLANG_DIR)/.clang-format . 
	clang-format -i *.c *.h $(COMMON_DIR)/*.c $(COMMON_DIR)/*.h
	cppcheck *.c *.h
	rm .clang-format

s21_grep: main.c grep.c $(COMMON_DIR)/common.c
	$(CC) $(CFLAGS) $^ -o s21_grep

debug: main.c grep.c $(COMMON_DIR)/common.c
	$(CC) $(CFLAGS) -g $^ -o s21_grep
	gdb ./s21_grep

test: 
	bash GODDESS_TEST.sh

clean: 
	rm -f s21_grep log.txt

valgrind: s21_grep 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=log.txt ./$< --file reg.txt --invert-match --regexp ^[ComedianBlAck0-9]* -c *.txt && grep "ERROR SUMMARY" log.txt
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=log.txt ./$< -ls -e ben*o -f no.txt doesntexist.txt && grep "ERROR SUMMARY" log.txt
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=log.txt ./$< -ils -e ben*o doesntexist.txt symbols.txt && grep "ERROR SUMMARY" log.txt


rebuild: clean all
