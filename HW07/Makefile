

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFALGS = -DTEST_MERGESORT -DTEST_MERGESSORT -DTEST_MERGE

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

main: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o main

c.o:
	$(GCC) $(TESTFALGS) -c $*.c

#need test mem for out2 and 3

testmemory: main
	$(VAL) ./main Input/Test1 output1

testall: test1 test2 test3

testadd: main
	test1
	test2
	test3

test1: main
	./main Input/test1.txt output1.txt
	diff -i -w output1.txt Expected/Expected1.txt

test2: main
	./main Input/test2.txt output2.txt
	diff -i -w output2.txt Expected/Expected2.txt

test3: main
	./main Input/test3.txt output3.txt
	diff -i -w output3.txt Expected/Expected3.txt

clean:
	rm -f main *.o main?
