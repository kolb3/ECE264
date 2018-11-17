WARNING =-Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_SPLIT -DTEST_MERGE -DTEST_SORT -DLINKEDLIST

VALGRIND = valgrind --tool=memcheck --verbose --log-file

SRCS = main.c hw14.c

OBJS = $(SRCS:%.c=%.o)

hw14: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw14

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: hw14
	$(VALGRIND)= ./hw14 inputs/test1.txt > output1.txt

testall: test1 test2 test3

test1: hw14
	./hw14 inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt
test2: hw14
	./hw14 inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt
test3: hw14
	./hw14 inputs/test3.txt > output3.txt
	diff output3.txt expected/expected3.txt

clean:
	rm -f $(OBJS) $(TARGET)
