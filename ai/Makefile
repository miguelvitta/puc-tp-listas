CC = clang
CFLAGS = -Wall -Wextra -Wshadow
DEBUG_FLAGS = -O0 -g3 -fsanitize=address -fno-omit-frame-pointer

SRCS = $(shell find . -type f -name '*.c')

BINARIES = $(SRCS:.c=)

all: $(BINARIES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lm

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(BINARIES)

.PHONY: clean
clean:
	rm -f $(BINARIES)
