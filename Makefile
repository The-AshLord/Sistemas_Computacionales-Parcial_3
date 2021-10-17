CFLAGS = -g -Wall 
CC = gcc
_DEPS = $(wildcard *.h)
_SRC = $(wildcard *.c)
_OBJS = $(patsubst %.c, %.o, $(_SRC))

app: $(_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ 

%.o: %.c $(_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	find . -name "*.o" -delete
	rm app
