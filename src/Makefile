SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.c=.o)

OBJS: chibi.h

chibicc: $(OBJS)
	g++ -o $@ $(OBJS)

