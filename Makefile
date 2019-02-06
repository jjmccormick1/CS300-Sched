CC=clang
CXX=clang++
CFLAGS=-ggdb -Wall

process:
	@$(CC) $(CFLAGS) process.c -o process
vm:
	@$(CC) $(CFLAGS) vm.c -o vm
proc:
	@$(CC) $(CFLAGS) -c proc.c
proctest:
	@$(CC) $(CFLAGS) -c proctest.c
	@$(CC) $(CFLAGS) proc.o proctest.o -o proctest

all: process vm

test: proc proctest
	@./proctest
	@rm -f proctest

runproc: process
	@./process

runvm: vm
	@./vm 0.proc

clean:
	@rm -f process
	@rm -f vm
	#@rm -f *.proc
	@rm -f *.o