CC = gcc
CFLAGS = -I./include -Wall
LIBS = -lm

SRCS = src/main.c src/common_math.c src/logic_weather.c src/logic_solver.c
OBJS = $(SRCS:.c=.o)
TARGET = banhchung_app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)