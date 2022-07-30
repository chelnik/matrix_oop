NAME	=	s21_matrix_oop.a

SRC = s21_matrix_oop.cpp operators.cpp support.cpp

NAME_TEST = tests.cpp

OBJ		=	$(SRC:%.c=%.o)

CC 		= g++ -std=c++17

CFLAGS	= -Wall -Wextra -Werror

FLAGS_TEST_LIBS = -lgtest
all: $(NAME)

# Сборка библиотеки
$(NAME): $(OBJ) $(HEADER)
	@ar rcs $(NAME) $?
	@rm -f *.o

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
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

check: $(NAME)
	@echo ---------------------CPPCHECK---------------------
	cppcheck *.h $(SRC)
	@echo -------------------MEMORY_LEAKS-------------------
	$(CC) -g $(NAME_TEST) $(NAME) $(FLAGS_TEST_LIBS) -o unit.out
	CK_FORK=no leaks --atExit -- ./unit.out

l:
	@make clean
	$(CC) -g $(CFLAGS) $(NAME_TEST) $(SRC) $(FLAGS_TEST_LIBS) && ./a.out
	CK_FORK=no leaks --atExit -- ./a.out
	@make clean