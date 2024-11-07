CC = gcc
PROG = main.exe
SRC = main.c functions/function01.c
CFLAGS = -g

all: $(PROG)

$(PROG): $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	rm -f $(PROG)

.PHONY: all clean
