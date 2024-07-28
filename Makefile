TARGET = slib_test

SRC_DIRS = test/ slib/

CC = gcc
CFLAGS = -I . -Wall -Wextra -g

SRCS := $(shell find $(SRC_DIRS) -name '*.c')

TMP_DIR = tmp
OBJ_DIR = $(TMP_DIR)

OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all test test_build clean

all: test

test: $(TARGET)
	./$(TARGET)

test_build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(TMP_DIR) $(TARGET)
