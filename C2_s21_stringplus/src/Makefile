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

STRING_FUNCTIONS_DIR = s21_string_functions
SPRINT_SCAN_DIR = s21_sprint_scan
SPRINTF_HANDLERS_DIR = s21_sprint_scan/sprintf_handlers
TEST_DIR = test

STRING_SRCS = $(wildcard $(STRING_FUNCTIONS_DIR)/*.c)
SPRINT_SCAN_SRCS = $(wildcard $(SPRINT_SCAN_DIR)/*.c)
SPRINTF_HANDLERS_SRCS = $(wildcard $(SPRINTF_HANDLERS_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)

STRING_OBJS = $(STRING_SRCS:.c=.o)
SPRINT_SCAN_OBJS = $(SPRINT_SCAN_SRCS:.c=.o)
SPRINTF_HANDLERS_OBJS = $(SPRINTF_HANDLERS_SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

GCOV_REPORT_DIR = gcov_report
LCOV_REPORT_DIR = lcov_report

$(STRING_FUNCTIONS_DIR)/%.o: $(STRING_FUNCTIONS_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(SPRINT_SCAN_DIR)/%.o: $(SPRINT_SCAN_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(SPRINTF_HANDLERS_DIR)/%.o: $(SPRINTF_HANDLERS_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

all: format build

build: s21_string.a

rebuild: clean build

format:
# cp ../materials/linters/.clang-format .
	clang-format -i *.h $(STRING_FUNCTIONS_DIR)/*.c $(TEST_DIR)/*.c $(TEST_DIR)/*.h $(SPRINT_SCAN_DIR)/*.c $(SPRINT_SCAN_DIR)/*.h $(SPRINTF_HANDLERS_DIR)/*.c $(SPRINTF_HANDLERS_DIR)/*.h 
# rm .clang-format
	cppcheck *.h $(STRING_FUNCTIONS_DIR)/*.c $(TEST_DIR)/*.c $(TEST_DIR)/*.h $(SPRINT_SCAN_DIR)/*.c $(SPRINT_SCAN_DIR)/*.h $(SPRINTF_HANDLERS_DIR)/*.c $(SPRINTF_HANDLERS_DIR)/*.h 
# cppcheck --check-level=exhaustive *.c *.h #эта опция есть только в последних версиях

test: s21_string.a $(TEST_OBJS)
	$(CC) $(FLAGS) $(TEST_OBJS) s21_string.a $(TEST_LIBS) -o test_runner.o
	./test_runner.o

clean:
	rm -f $(STRING_OBJS) $(SPRINT_SCAN_OBJS) $(SPRINTF_HANDLERS_OBJS) $(TEST_OBJS) *.a *.txt *.o *.gcno *.gcda *.gcov *.info 
	rm -rf $(LCOV_REPORT_DIR)
	rm -rf $(GCOV_REPORT_DIR)

s21_string.a: $(STRING_OBJS) $(SPRINT_SCAN_OBJS) $(SPRINTF_HANDLERS_OBJS)
	ar -rc $@ $^
	ranlib $@

report.o: $(STRING_SRCS) $(SPRINT_SCAN_SRCS) $(SPRINTF_HANDLERS_SRCS) $(TEST_SRCS)
	$(CC) $(FLAGS) $(REPORT_FLAGS) $^ -o report.o $(TEST_LIBS)
	./report.o

lcov_report: report.o
	mkdir -p $(LCOV_REPORT_DIR) && gcov *.gcda
	lcov --capture --directory . --output-file $(LCOV_REPORT_DIR)/coverage.info
	genhtml $(LCOV_REPORT_DIR)/coverage.info --output-directory $(LCOV_REPORT_DIR)
	mkdir -p $(LCOV_REPORT_DIR)/gc && mv *.gcno *.gcda *.gcov $(LCOV_REPORT_DIR)/gc
	open $(LCOV_REPORT_DIR)/index.html

gcov_report: report.o
	mkdir -p $(GCOV_REPORT_DIR) && gcov *.gcda
	gcovr -r . --html --html-details -o $(GCOV_REPORT_DIR)/index.html
	mkdir -p $(GCOV_REPORT_DIR)/gc && mv *.gcno *.gcda *.gcov $(GCOV_REPORT_DIR)/gc
	open $(GCOV_REPORT_DIR)/index.html

memcheck: test
	$(MEM) ./test_runner.o
	@echo "Memory checking output is written in memory.txt"
	@cat memory.txt | grep "ERROR SUMMARY"

.PHONY: all build rebuild format test clean lcov_report gcov_report memcheck
