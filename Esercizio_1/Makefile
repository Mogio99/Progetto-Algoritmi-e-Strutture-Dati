
all: bin/create_array bin/create_array_test

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/create_array: build/merg_sort.o build/create_array_main.o $(COMMON_DEPS)
	$(CC) -o bin/merg_sort build/merg_sort.o build/create_array_main.o

bin/create_array_test: build/merg_sort.o build/ordered_tests.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/ordered_tests build/ordered_tests.o build/merg_sort.o build/unity.o


clean:
	rm -f build/* bin/*
