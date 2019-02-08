CC=clang
CXX=clang++
CFLAGS=-ggdb -Wall
.DEFAULT_GOAL := all

procgen:
	@$(CC) $(CFLAGS) procgen.c -o procgen

sched: proc
	@$(CC) $(CFLAGS) -c sched.c
	@$(CC) $(CFLAGS) proc.o sched.o -o sched

proc:
	@$(CC) $(CFLAGS) -c proc.c

proctest:
	@$(CC) $(CFLAGS) -D TEST proc.c -o proctest
	@./proctest

all: procgen sched

test: proctest
	@./proctest
	@rm -f proctest

runproc: procgen
	@./procgen

runsched: sched
	@./sched 0.proc

clean:
	@rm -f sched
	@rm -f procgen
	@rm -f proctest
	#@rm -f *.proc
	@rm -f *.o