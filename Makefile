CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb

heap: malloc.c
	$(CC) $(CFLAGS) -o heap malloc.c