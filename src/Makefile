SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.c=.o)

OBJS: chibi.h

chibicc: $(OBJS)
	g++ -o $@ $(OBJS)

test:
	./chibicc test/step5/assign_val.c

