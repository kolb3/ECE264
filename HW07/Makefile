

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

<<<<<<< HEAD
TESTFALGS = -DTEST_MERGE -DTEST_MERGESORT -DTEST_MERGESSORT
=======
TESTFALGS = -DTEST_MERGESORT -DTEST_MERGESSORT -DTEST_MERGE
>>>>>>> eda63872c1664935d6adfa382084db6ce285f610

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

<<<<<<< HEAD
hw07: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw07
=======
main: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o main
>>>>>>> eda63872c1664935d6adfa382084db6ce285f610

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

<<<<<<< HEAD
#Make sure to add testing mem 2 and 3 for inputs 2 and 3 also
testmemory: $(TARGET)
	$(VAL) ./main Input/Test1

=======
#need test mem for out2 and 3

testmemory: main
	$(VAL) ./main Input/Test1 output1

testall: test1 test2 test3
>>>>>>> eda63872c1664935d6adfa382084db6ce285f610

testall: test1 test2 test3

test1: hw07
	./hw07 Input/Test1 output1
	diff -i -w output1 Expected/Expected1

test2: hw07
	./hw07 Input/Test2 output2
	diff -i -w output2 Expected/Expected2

test3: hw07
	./hw07 Input/Test3 output3
	diff -i -w output3 Expected/Expected3

clean:
<<<<<<< HEAD
	rm -f hw07 *.o output
=======
	rm -f main *.o main?
>>>>>>> eda63872c1664935d6adfa382084db6ce285f610
