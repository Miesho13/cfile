CC=/bin/clang
FLAG=-Wall -Wextra
TEST=test.c
SRC_LIB=clib.c
SRC_LIB=clib.c

all: lib test

lib: src/cfile.c
	${CC} -c src/cfile.c ${FLAG} -o build/cfile.o

test:
	${CC} src/test.c build/cfile.o -o build/test
