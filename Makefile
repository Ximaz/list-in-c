##
## EPITECH PROJECT, 2024
## List in C
## File description:
## Makefile
##

LIB_PATH		:=	/usr/local/lib
INCLUDE_PATH	:=	/usr/local/include/list

CC				:=	gcc
CPPFLAGS		:=	-Iinclude/
CFLAGS 			:=	-Wall -Wextra -Werror -pedantic -ansi -fPIC 		 \
					-fno-delete-null-pointer-checks -fno-strict-overflow \
					-fno-strict-aliasing -ftrivial-auto-var-init=zero    \
					-Wformat -Wimplicit-fallthrough 					 \
					-U_FORTIFY_SOURCE -D_GLIBCXX_ASSERTIONS 			 \
					-fstack-protector-strong

ifeq ($(PLATFORM),x86_64)
	CFLAGS		+=	-fcf-protection=full -Wl,-z,nodlopen -Wl,-z,noexecstack \
					-Wl,-z,relro -Wl,-z,now -fstack-clash-protection 		\
					-fstrict-flex-arrays=3 -Wtrampolines
endif

ifeq ($(PLATFORM),aarch64)
	CFLAGS		+=	-mbranch-protection=standard
endif

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

tests/%.o:	CFLAGS = -Wall -Wextra -Werror
tests/%.o:	tests/%.c
	@$(CC) $(TESTS_CFLAGS) $(CPPFLAGS) -o $@ -c $<

all:	liblist.a	liblist.so	liblist.dylib

liblist.so:	$(OBJS)
	@$(CC) -shared $(CFLAGS) $(OBJS) -o $@

liblist.dylib:	$(OBJS)
	@$(CC) -shared $(CFLAGS) $(OBJS) -o $@

liblist.a:	$(OBJS)
	@ar -rcs $@ $(OBJS)

tests_run:	CFLAGS += -g --coverage
tests_run:	fclean	$(OBJS)	$(TESTS_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(TESTS_OBJS) -o unit_tests -lcriterion
	@CRITERION_NO_EARLY_EXIT=1 ./unit_tests
	@gcovr -e tests .

install:	all
	@mkdir -p $(INCLUDE_PATH)
	@mv liblist.a $(LIB_PATH)
	@mv liblist.so $(LIB_PATH)
	@mv liblist.dylib $(LIB_PATH)
	@cp include/list.h $(INCLUDE_PATH)
	@echo "Lib installed. Use 'ldconfig' or 'update_dyld_shared_cache' to \
	refresh ld cache"

uninstall:
	@$(RM) $(LIB_PATH)/liblist.a
	@$(RM) $(LIB_PATH)/liblist.so
	@$(RM) $(LIB_PATH)/liblist.dylib
	@$(RM) $(INCLUDE_PATH)/list.h
	@echo "Lib uninstalled. Use 'ldconfig' or 'update_dyld_shared_cache' to \
	refresh ld cache"

valgrind:	tests_run
	valgrind $(VALGRIND_FLAGS) ./unit_tests

clean:
	@$(RM) $(OBJS)
	@$(RM) $(TESTS_OBJS)
	@$(RM) $(shell find . -type f -name '*.gcno')
	@$(RM) $(shell find . -type f -name '*.gcda')

fclean:	clean
	@$(RM) liblist.so liblist.a liblist.dylib
	@$(RM) unit_tests

re:	fclean	all
