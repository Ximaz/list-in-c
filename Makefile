CC				:=	gcc
NAME			:=	liblist.so
CPPFLAGS		:=	-Iinclude/

SRCS			:=	$(shell find src -name '*.c')
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
	$(CC) $(TESTS_CFLAGS) $(CPPFLAGS) -o $@ -c $<

all:	$(NAME)

$(NAME):	CFLAGS = -Wall -Wextra -Werror -pedantic -ansi
$(NAME):	clean	$(OBJS)
	$(CC) -shared -fPIC $(OBJS) -o $(NAME)

tests_run:	CFLAGS = -g -Wall -Wextra -Werror -pedantic -ansi --coverage
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
