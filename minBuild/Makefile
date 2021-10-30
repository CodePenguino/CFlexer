# Quick note, please install mingw for this!

# Change this to you compiler of choice, I don't mind
CC = gcc
SRC = $(wildcard ../src/*.c) $(wildcard ../src/*/*.c) $(wildcard ../src/*/*/*.c) $(wildcard ../src/*/*/*/*.c)
LIBS = -lmingw32 -lglew32 -lglfw3dll -lopengl32
DIRS = -I../include/ -L../lib/

all: $(SRC)
	$(CC) $(SRC) $(DIRS) $(LIBS)
