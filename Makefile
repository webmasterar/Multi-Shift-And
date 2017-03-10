ifdef SystemRoot
	RM = del /Q
	EXT = .exe
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		EXT =
	endif
endif

CC = gcc
# -O3
CFLAGS = -Wall -g -msse4.2 -fomit-frame-pointer -funroll-loops -lm -I .

all: multi-shift-and
	$(CC) $(CFLAGS) -o multi-shift-and$(EXT) multi-shift-and.o main.o

multi-shift-and: clean
	$(CC) $(CFLAGS) -c multi-shift-and.c main.c

clean:
	$(RM) multi-shift-and.o main.o multi-shift-and$(EXT)
