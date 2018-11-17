WARNING =-Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_SPLIT -DTEST_DIV -DLINKEDLIST

VALGRIND = valgind --tool=memcheck --verbose --log-file

SRCS = main.c hw13.c

OBJS = $(SRCS:%.c=%.o)

hw13: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw13

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./hw13

testall: test1 test2 test3

test1: hw13
	./hw13 inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt
test2: hw13
	./hw13 inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt
test3: hw13
	./hw13 inputs/test3.txt > output3.txt
	diff output3.txt expected/expected3.txt

clean:
	rm -f $(OBJS) $(TARGET)
