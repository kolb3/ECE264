WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFLAGS = -DTEST_MAIN -DTEST_FUSE -DTEST_CENT -DTEST_DIST -DTEST_LINKEDLISTCREATE -DTEST_CREATENODE

SRCS = main.c hw18.c
OBJS = $(SRCS:%.c=%.o)

hw18: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw18

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10

test1: hw18
		./hw18 inputs/test1.txt > output1.txt
		diff output1.txt expected/expected1.txt
test2: hw18
		./hw18 inputs/test2.txt > output2.txt
		diff output2.txt expected/exptected2.txt
test3: hw18
		./hw18 inputs/test3.txt > output3.txt
		diff output3.txt expected/expected3.txt
test4: hw18
		./hw18 inputs/test4.txt > output4.txt
		diff output4.txt expected/expected.txt

clean: # remove all machine generated files
	rm -f split *.o output* hw18
