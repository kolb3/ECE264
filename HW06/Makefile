# ***
# *** Please modify this file as required
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFALGS = -DTEST_MAIN -DTEST_COMP -DTEST_FILL -DTEST_WRITE -DTEST_COUNT

SRCS = main.c vector.c
OBJS = $(SRCS:%.c=%.o)

main: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o main

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testall:test1 test2 test3
	

test1: main
	./main inputs/test1.bin output1.bin
	diff -i -w output1.bin expected/expected1.bin

test2: main
	./main inputs/test2.bin output2.bin
	diff -i -w output2.bin expected/expected2.bin

test3: main
	./main inputs/test3.bin output3.bin
	diff -i -w output3.bin expected/expected3.bin

clean: # remove all machine generated files
	rm -f main *.o
