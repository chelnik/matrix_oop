NAME	=	s21_matrix_oop.a

SRC = s21_matrix_oop.cpp operators.cpp support.cpp

NAME_TEST = tests.cpp

OBJ		=	$(SRC:%.c=%.o)

CC 		= g++ -std=c++17

CFLAGS	= -Wall -Wextra -Werror

FLAGS_TEST_LIBS = -lgtest
all: 
# $(NAME)

test:
	@make clean
	$(CC) -g $(CFLAGS) $(NAME_TEST) $(SRC) $(FLAGS_TEST_LIBS) && ./a.out
	@make clean

clean:
	@rm -rf *.o *.so *.gcda *.gcno *.gch rep.info *.html *.css report *.txt *.info *.dSYM *.out

fclean: clean
	@rm -f $(NAME)
	@rm -rf report


lint:
	@cp ../materials/linters/CPPLINT.cfg ./
	@python3 ./../materials/linters/cpplint.py --extensions=cpp *.cpp *.h
	@rm -f CPPLINT.cfg

gc:
	make gcov_report
gcov_report: all
	$(CC) $(CFLAGS) --coverage $(NAME_TEST) $(SRC) $(FLAGS_TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html