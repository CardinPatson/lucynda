### 
## Makefile skeleton
## INFO0030: Projet 1
## 
### 

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes
LD=gcc
LDFLAGS=":f:i:o:"

# Files
EXEC=pnm
MODULES=main.c pnm.c
OBJECTS=main.o pnm.o

## Rules

#concept

# target... : prerequist..
# 			recipe 

# target : (name of a file generate by the program : elf file or the name of action to carry out : clean)
# prerequist : (le fichier en entré utilisé pour créer le target file : .c file)
#recipe : action que le make va effectuer

all: $(EXEC)

pnm: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

pnm.o: pnm.c
	$(CC) -c pnm.c -o pnm.o $(CFLAGS)

clean:
	rm -f *.o $(EXEC) *~

