WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFLAGS = -DTEST_MAIN -DTEST_CREATEBST -DTEST_DIST -DTEST_PRINT

SRCS = main.c bst.c

OBJS = $(SRCS:%.c=%.o)

hw17: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw17

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testall: test1 test2 test3 test4 test5 test6 test7

test1: hw17
	./hw17 inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt
test2: hw17
	./hw17 inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt
test3: hw17
	./hw17 inputs/test3.txt > output3.txt
	diff output3.txt expected/expected3.txt
test4: hw17
	./hw17 inputs/test4.txt > output4.txt
	diff output4.txt expected/expected4.txt
test5: hw17
	./hw17 inputs/test5.txt > output5.txt
	diff output5.txt expected/expected5.txt
test6: hw17
	./hw17 inputs/test6.txt > output6.txt
	diff output6.txt expected/expected6.txt
test7: hw17
	./hw17 inputs/test7.txt > output7.txt
	diff output7.txt expected/expected7.txt
