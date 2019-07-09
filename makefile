PROJECT = yodaka
PROJECTDIR := $(HOME)/$(PROJECT)
#srcdir := $(HOME)/$(PROJECT)/src

CC = gcc

.PHONY : all
all :
	$(MAKE) -C src PROJECTDIR=$(PROJECTDIR)
	$(CC) $(PROJECTDIR)/obj/* -o yodaka
