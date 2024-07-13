CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -Iinc `sdl2-config --cflags` -lm
LDFLAGS = `sdl2-config --libs` -lm

SRC = src/main.c src/maze.c
OBJ = obj/main.o obj/maze.o
TARGET = The-Maze

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

obj/main.o: src/main.c inc/maze.h
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/maze.o: src/maze.c inc/maze.h
	$(CC) $(CFLAGS) -c src/maze.c -o obj/maze.o

clean:
	rm -f $(OBJ) $(TARGET)

