CC = gcc
CFLAGS = -I $(PROJECTDIR)/include

.PHONY : all
all : main.o cmd.o net.o analyze.o

main.o : main.c
	$(CC) $(CFLAGS) -c $< -o $(PROJECTDIR)/obj/$@

cmd.o : cmd.c
	$(CC) $(CFLAGS) -c $< -o $(PROJECTDIR)/obj/$@

net.o : net.c
	$(CC) $(CFLAGS) -c $< -o $(PROJECTDIR)/obj/$@

analyze.o : analyze.c
	$(CC) $(CFLAGS) -c $< -o $(PROJECTDIR)/obj/$@


