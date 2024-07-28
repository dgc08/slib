TEST_FLAGS = -a=omgFirstTryFeatureWorkingNoDebuggingILoveTheWorld 2ndFlag
TARGET = slib_test

SRC_DIRS = test/ lib/slib/src

CC = gcc
CFLAGS = -I lib -Wall -Wextra -g

SRCS := $(shell find $(SRC_DIRS) -name '*.c')

TMP_DIR = tmp
OBJ_DIR = $(TMP_DIR)

OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all test test_build clean

all: test test_build

test: $(TARGET)
	echo && ./$(TARGET) $(TEST_FLAGS)

test_build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(TMP_DIR) $(TARGET)
