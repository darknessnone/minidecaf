SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.c=.o)

chibicc: $(OBJS)
	g++ -o $@ $(OBJS)

test: chibicc
	./chibicc test/test2/nested_ops_2.c

