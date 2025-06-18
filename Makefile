CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lglfw -lGLEW -lGL
SRC = main.cpp
OUT = main

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(LDFLAGS)

clean:
	rm -f $(OUT)
