
all: bin/edit_distance_dyn bin/test_edit_distance

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/edit_distance_dyn :  build/edit_distance_dyn.o  build/load_array.o $(COMMON_DEPS)
	$(CC) -o  bin/edit_distance_dyn build/edit_distance_dyn.o build/load_array.o

bin/test_edit_distance : build/edit_distance_dyn.o build/edit_distance_test.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/edit_distance_test  build/edit_distance_test.o build/edit_distance_dyn.o build/unity.o

clean:
	rm -f build/* bin/*
