CC = gcc
SRC = example.c
O = example
CFLAGS = -m32
ALL:
	$(CC) $(SRC)  $(CFLAGS) -o $(O)


