WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_READHEADER -DTEST_DECODE -DTEST_MERGELIST -DDO_NOT_MODIFY

SRCS = main.c tree.c utility.c list.c decode.c
OBJS = $(SRCS:%.c=%.o)

hw19: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw21

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: hw21
		$(VAL) ./hw21 input/input1.bin output1.txt

testall: test1 test2 test3 test4 test5 test6 test7 test8

test1: hw21
	./hw21 input/input1.bin output1.txt
	diff output1.txt expected/expected1.txt
test2: hw21
	./hw21 input/input2.bin output2.txt
	diff output2.txt expected/expected2.txt
test3: hw21
	./hw21 input/input3.bin output3.txt
	diff output3.txt expected/expected3.txt
test4: hw21
	./hw21 input/input4.bin output4.txt
	diff output4.txt expected/expected4.txt
test5: hw21
	./hw21 input/input5.bin output5.txt
	diff output5.txt expected/expected5.txt
test6: hw21
	./hw21 input/input6.bin output6.txt
	diff output6.txt expected/expected6.txt
test7: hw21
	./hw21 input/input7.bin output7.txt
	diff output7.txt expected/expected7.txt
test8: hw21
	./hw21 input/input8.bin output8.txt
	diff output8.txt expected/expected8.txt


clean: # remove all machine generated files
	rm -f split *.o output* hw21
