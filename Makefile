NAME			:=	c_spice
CC				:=	gcc
CPPFLAGS		:=	-Iinclude/

CFLAGS			:=	-g -Wall -Wextra -Werror -pedantic -ansi --coverage
SRCS			:=	$(shell find . -type f ! -name 'tests_*.c' ! -name 'main.c' -name '*.c')
OBJS			:=	$(SRCS:.c=.o)

TESTS_CFLAGS	:=	-g -Wall -Wextra -Werror
TESTS_SRCS		:=	$(shell find tests -type f -name 'tests_*.c')
TESTS_OBJS		:=	$(TESTS_SRCS:.c=.o)

VALGRIND_FLAGS	:=	-s							\
					--leak-check=full			\
					--track-origins=yes			\
					--read-var-info=yes			\
					--trace-children=yes		\
					--show-leak-kinds=all		\
					--read-inline-info=yes		\
					--errors-for-leak-kinds=all

RM				:=	rm -rf

tests/%.o:	tests/%.c
	$(CC) $(TESTS_CFLAGS) $(CPPFLAGS) -o $@ -c $< -lcriterion

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) main.c -o $(NAME)

tests_run:	clean	$(OBJS)	$(TESTS_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(TESTS_OBJS) -o unit_tests -lcriterion
	CRITERION_NO_EARLY_EXIT=1 ./unit_tests
	gcovr -e tests .

valgrind:	tests_run
	valgrind $(VALGRIND_FLAGS) ./unit_tests

clean:
	$(RM) $(OBJS)
	$(RM) $(TESTS_OBJS)
	$(RM) $(shell find . -type f -name '*.gcno')
	$(RM) $(shell find . -type f -name '*.gcda')

fclean:	clean
	$(RM) $(NAME)
	$(RM) unit_tests

re:	fclean	all
