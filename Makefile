CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lglfw -lGLEW -lGL
SRC = main.c
OUT = main

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(LDFLAGS)

clean:
	rm -f $(OUT)
