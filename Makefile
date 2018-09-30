CC=gcc
DEPS=bigint.h
CFLAGS=-I.
OBJS=test.o bigint.o

%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

test: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm *.o
	rm test
