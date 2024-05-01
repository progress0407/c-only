CC = gcc
TARGET = a.out
OBJS = main.o foo.o bar.o
CFLAGS = -g

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

.c.o:
	$(CC) -c -o $@ $<

clean:
	rm *.o $(TARGET)