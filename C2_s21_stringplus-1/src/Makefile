GCC = gcc -Wall -Werror -Wextra -std=c11
LIB = -L. s21_string.a -lcheck -lsubunit -lm
GCOV = -fprofile-arcs -ftest-coverage --coverage

all: build

build: s21_string.a

s21_string.a: 
	$(GCC) -c s21_string.c -o s21_string
	ar rcs s21_string.a s21_string

clean:
	rm -rf *.o *.a *.gcov *.gcda *.gcno *.html *.css test_main s21_string

rebuild: clean build

test: rebuild
	$(GCC) test_main.c -o test_main $(LIB)
	./test_main

clang:
	clang-format -i *.h *.c

gcov_report: rebuild
	$(GCC) $(GCOV) -o gcov_main.gcov test_main.c $(LIB)
	./gcov_main.gcov
	gcov test_main.c

gcovr:
	gcovr -r . --html --html-details -o coverage_report.html
