SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.c=.o)

chibicc: $(OBJS)
	g++ -o $@ $(OBJS)

test:
	./chibicc test/step4/and_true.c

