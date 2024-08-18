CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -Iinc `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lm

OBJDIR = obj
SRCDIR = src
BINDIR = bin

OBJS = $(OBJDIR)/main.o $(OBJDIR)/maze.o
TARGET = The-Maze

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

all: $(BINDIR)/$(TARGET)

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(TARGET)

