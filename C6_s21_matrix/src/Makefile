CC = gcc
FLAGS = -std=c11 -Wall -Werror -Wextra -pedantic # -g
REPORT_FLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname)

ifeq ($(OS), Linux)
	TEST_LIBS = -lcheck -lsubunit -lrt -lm -lpthread
	MEM = valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=memory.txt --verbose
else #Darwin
	TEST_LIBS = $(shell pkg-config --cflags --libs check) -lm
	MEM = leaks --atExit  --log-file=memory.txt -- 
endif

SRC_DIR = .
TEST_DIR = test

SRCS = $(wildcard $(SRC_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)

OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

GCOV_DIR = gcov_report
LCOV_DIR = lcov_report

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

all: format build

build: s21_matrix.a

rebuild: clean build

format:
#	cp ../materials/linters/.clang-format .
	clang-format -i *.h $(SRC_DIR)/*.c $(TEST_DIR)/*.c $(TEST_DIR)/*.h
#	rm .clang-format
	cppcheck *.h *.h $(SRC_DIR)/*.c $(TEST_DIR)/*.c $(TEST_DIR)/*.h
# cppcheck --check-level=exhaustive *.c *.h #эта опция есть только в последних версиях

test: s21_matrix.a $(TEST_OBJS)
	$(CC) $(FLAGS) $(TEST_OBJS) s21_matrix.a $(TEST_LIBS) -o test_runner.o
	./test_runner.o

clean:
	rm -f $(OBJS) $(TEST_OBJS) *.o *.a *.txt *.gcno *.gcda *.gcov *.info 
	rm -rf $(LCOV_DIR)
	rm -rf $(GCOV_DIR)

s21_matrix.a: $(OBJS)
	ar -rc $@ $^
	ranlib $@

report: $(SRCS) $(TEST_SRCS)
	$(CC) $(FLAGS) $(REPORT_FLAGS) $^ -o report.o $(TEST_LIBS)
	./report.o

lcov_report: report
	mkdir -p $(LCOV_DIR) && gcov *.gcda
	lcov --capture --directory . --output-file $(LCOV_DIR)/coverage.info
	genhtml $(LCOV_DIR)/coverage.info --output-directory $(LCOV_DIR)
	open $(LCOV_DIR)/index.html

gcov_report: report
	mkdir -p $(GCOV_DIR) && gcov *.gcda
	gcovr -r . --html --html-details -o $(GCOV_DIR)/index.html
	open $(GCOV_DIR)/index.html

memcheck: test
	$(MEM) ./test_runner.o
	@echo "Memory checking output is written in memory.txt"
	@cat memory.txt | grep "ERROR SUMMARY"

.PHONY: s21_matrix.a all build rebuild format test clean lcov_report gcov_report memcheck
