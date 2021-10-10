CC = gcc
SRC = $(wildcard src/*.c) $(wildcard src/*/*.c) $(wildcard src/*/*/*.c)
LIBS = -lmingw32 -lglew32 -lglfw3dll -lopengl32
DIRS = -I./include/ -L./lib/

all: $(SRC)
	$(CC) $(SRC) $(DIRS) $(LIBS)